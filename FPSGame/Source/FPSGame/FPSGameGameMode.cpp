// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSGameGameMode.h"

#include <set>

#include "FPSGameCharacter.h"
#include "FPSGameState.h"
#include "SpawnPoint.h"
#include "WeaponManager.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

namespace MatchState
{
	const FName StartingRound = FName(TEXT("StartingRound"));
	const FName EndingRound = FName(TEXT("EndingRound"));
}


AFPSGameGameMode::AFPSGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AFPSGameGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AFPSGameGameMode::SpawnPlayer(APlayerController* NewPlayer, int32 TeamID)
{
	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPoint::StaticClass(), SpawnPoints);
	APlayerStart* SpawnPoint = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass()));

	for(int i = 0; i < SpawnPoints.Num(); i++)
	{
		ASpawnPoint* SP = Cast<ASpawnPoint>(SpawnPoints[i]);
		if(SP->TeamID == TeamID && !SP->bHasPlayer)
		{
			SpawnPoint = SP;
			SP->bHasPlayer = true;
			break;
		}
	}
	
	if(!SpawnPoint)
	{
		SpawnPoint = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass()));
	}
	
	APawn* PlayerPawn = Cast<APawn>(GetWorld()->SpawnActor(Player, &SpawnPoint->GetActorTransform()));
	//NewPlayer->SetInputMode(FInputModeGameAndUI());

	if(PlayerPawn)
	{
		NewPlayer->Possess(PlayerPawn);

		if(AFPSGameCharacter* Character = Cast<AFPSGameCharacter>(PlayerPawn))
		{
			Character->WeaponManager->SetWeapon(GetRoundWeapon().WeaponData);
		}
	}
}

void AFPSGameGameMode::OnPlayerJoinedTeam(int32 TeamID, APlayerController* PC)
{
	if(GetMatchState() == MatchState::WaitingToStart  /*/&&BothTeamsFull() /*/)
	{
		SetMatchState(MatchState::StartingRound);
		AFPSGameState* GS = GetWorld()->GetGameState<AFPSGameState>();
		GS->CurrentRound = 1;
		GS->bCanInteract = false;
		GS->StartMatch();
		RespawnAllPlayers();
	}
}

void AFPSGameGameMode::EndRound(int32 Winner)
{
	for(FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if(PlayerController)
		{
			AFPSGamePlayerController* PC = Cast<AFPSGamePlayerController>(PlayerController);
			if(PC)
			{
				PC->Client_OnEndRound(Winner);
			}
		}
	}

	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPoint::StaticClass(), SpawnPoints);

	for(int i = 0; i < SpawnPoints.Num(); i++)
	{
		ASpawnPoint* SP = Cast<ASpawnPoint>(SpawnPoints[i]);
		SP->bHasPlayer = false;
	}
	
	SetMatchState(MatchState::EndingRound);
	GetWorldTimerManager().SetTimer(BeginNextRoundTimerHandle, this, &AFPSGameGameMode::BeginNextRound, 10.f, false);

	if(AFPSGameState* GS = GetWorld()->GetGameState<AFPSGameState>())
	{
		if(GS->CurrentRound >= 5)
		{
			//end game
		}
	}
}

bool AFPSGameGameMode::ReadyToStartMatch_Implementation()
{
	return Super::ReadyToStartMatch_Implementation();
}

void AFPSGameGameMode::RespawnAllPlayers()
{
	for(FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if(PlayerController)
		{
			APawn* PlayerPawn = PlayerController->GetPawn();

			if(AFPSGameCharacter* Character = Cast<AFPSGameCharacter>(PlayerPawn))
			{
				Character->WeaponManager->CurrentWeapon->Destroy();
				Character->WeaponManager->CurrentWeapon->ThirdPersonWeapon->Destroy();
			}
			if(PlayerPawn)
			{
				PlayerController->UnPossess();
				PlayerPawn->Destroy();
			}

			const AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(PlayerController->PlayerState);
			SpawnPlayer(PlayerController, PlayerState->TeamID);
		}
	}
}

FRoundWeapons AFPSGameGameMode::GetRoundWeapon()
{
	AFPSGameState* GS = GetWorld()->GetGameState<AFPSGameState>();
	for(int i = 0; i < RoundWeapons.Num(); i++)
	{
		if(RoundWeapons[i].Round == GS->CurrentRound)
		{
			return RoundWeapons[i];
		}
	}

	return RoundWeapons[0];
}

void AFPSGameGameMode::BeginNextRound()
{
	SetMatchState(MatchState::StartingRound);
	AFPSGameState* GS = GetWorld()->GetGameState<AFPSGameState>();
	GS->bCanInteract = false;
	GS->StartMatch();
	GS->CurrentRound++;
	RespawnAllPlayers();
}

bool AFPSGameGameMode::BothTeamsFull()
{
	const AFPSGameState* GS = GetWorld()->GetGameState<AFPSGameState>();
	return GS->RedTeam.PlayerStates.Num() >= TeamSize && GS->BlueTeam.PlayerStates.Num() >= TeamSize;
}
