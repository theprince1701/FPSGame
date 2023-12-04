// Copyright Epic Games, Inc. All Rights Reserved.


#include "FPSGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "FPSGameGameMode.h"
#include "FPSGameInstance.h"
#include "FPSGameState.h"
#include "GameHUD.h"
#include "Spectator.h"
#include "Camera/CameraComponent.h"
#include "Net/NetPing.h"
#include "Net/UnrealNetwork.h"

void AFPSGamePlayerController::PawnDied(APlayerState* Killer)
{
	bPlayerDead = true;
	if(AFPSGameCharacter* CH = Cast<AFPSGameCharacter>(GetPawn()))
	{
		PlayerPawnActor = CH;
		
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		const FVector Loc = CH->GetFirstPersonCameraComponent()->GetComponentLocation();
		const FRotator Rot = CH->GetFirstPersonCameraComponent()->GetComponentRotation();

		ASpectator* SP =  GetWorld()->SpawnActor<ASpectator>(SpectatorPawnSubclass, Loc, Rot, SpawnParameters);

		if(AFPSGameCharacter* KillerCharacter = Cast<AFPSGameCharacter>(Killer->GetPawn()))
		{
			SP->Init(KillerCharacter, Loc, Rot);
		}
		
		UnPossess();
		Possess(SP);

		CurrentRespawnTimer = RespawnTimer;
		GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &AFPSGamePlayerController::RespawnTick, 1.f, true);
		Client_OnDeath(Killer);
		

		if(AFPSGamePlayerController* KillerController = Cast<AFPSGamePlayerController>(Killer->GetPlayerController()))
		{
			KillerController->Client_OnKill(PlayerState);
		}
	}
}


void AFPSGamePlayerController::RespawnTick()
{
	CurrentRespawnTimer -= 1;

	if(CurrentRespawnTimer <= 0)
	{
		if(PlayerPawnActor)
		{
			PlayerPawnActor->Destroy();
		}

		//respawn player

		if(AFPSGameGameMode* GameMode = Cast<AFPSGameGameMode>(GetWorld()->GetAuthGameMode()))
		{
		//	GameMode->SpawnPlayer(this, 0);
			Client_Respawn();
		}

		Client_Respawn();
		GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);
	}
}

void AFPSGamePlayerController::OnRep_Pawn()
{
	Super::OnRep_Pawn();

//	SetInputMode(FInputModeGameAndUI());
}

void AFPSGamePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (LocalPlayer)
	{
		UGameViewportClient* ViewportClient = LocalPlayer->ViewportClient;
		if (ViewportClient)
		{
			UWorld* World = ViewportClient->GetWorld();
			if (World)
			{
				UNetConnection* Connection = GetNetConnection();
				if (Connection)
				{
					PacketLoss = Connection->OutPacketsLost;

					if(PlayerState)
					{
						Ping = PlayerState->GetPingInMilliseconds();
					}
					FPS = 1.0f / DeltaSeconds;
				}
			}
		}
	}
}

void AFPSGamePlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	UFPSGameInstance* GameInstance = Cast<UFPSGameInstance>(GetWorld()->GetGameInstance());

	Server_SetName(GameInstance->GetPlayerUsername());
}

void AFPSGamePlayerController::TogglePaused()
{
	bPaused = !bPaused;
//	Pause();

	SetShowMouseCursor(bPaused);

	if(AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->TogglePauseUI(bPaused);
	}
}

void AFPSGamePlayerController::Server_SetName_Implementation(const FString& PlayerName)
{
	PlayerState->SetPlayerName(PlayerName);
}

void AFPSGamePlayerController::Client_OnHit_Implementation(FVector Location)
{
	if(AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->OnHit(GetPawn(), Location);
	}
}

void AFPSGamePlayerController::Client_OnKill_Implementation(APlayerState* Victim)
{
	if(AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->OnKill(Victim->GetPlayerName());
	}
}

void AFPSGamePlayerController::Client_OnDeath_Implementation(APlayerState* Killer)
{
	if(AFPSGameCharacter* CH = Cast<AFPSGameCharacter>(Killer->GetPawn()))
	{
		CH->ToggleOutline(true);
	}

	if(const AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->PlayerHUD->RemoveFromParent();
		GameHUD->CrossHairWidget->RemoveFromParent();
		GameHUD->DeathWidget->AddToViewport();
	}
}

void AFPSGamePlayerController::Client_Respawn_Implementation()
{
	if(const AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->PlayerHUD->AddToViewport();
		GameHUD->CrossHairWidget->AddToViewport();
		GameHUD->DeathWidget->RemoveFromParent();
	}
}

void AFPSGamePlayerController::OnHit(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage,
                                     const FHitResult& Hit)
{
	//do it locally for instant effect
	if(AFPSGameState* GameState = GetWorld()->GetGameState<AFPSGameState>())
	{
		GameState->OnHit(DamageInstigator, DamagedActor, Damage, Hit, true);
	}


	//send to server for auth and replication
	Server_OnHit(DamageInstigator, DamagedActor, Damage, Hit);
}

void AFPSGamePlayerController::Client_OnEndRound_Implementation(int32 Winner)
{
	if(AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->EndRound(Winner);
	}
}

void AFPSGamePlayerController::Server_OnHit_Implementation(AFPSGameCharacter* DamageInstigator,
                                                           AFPSGameCharacter* DamagedActor, float Damage, const FHitResult& Hit)
{
	if(AFPSGameState* GameState = GetWorld()->GetGameState<AFPSGameState>())
	{
		GameState->OnHit(DamageInstigator, DamagedActor, Damage, Hit, false);
	}
}

AFPSGamePlayerController::AFPSGamePlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFPSGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

//	SetInputMode(	FInputModeUIOnly());
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AFPSGamePlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFPSGamePlayerController, CurrentRespawnTimer);
}
