// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameState.h"

#include "FPSGameGameMode.h"
#include "GameHUD.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/DecalComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"

void AFPSGameState::Multicast_OnHit_Implementation(AFPSGameCharacter* DamageInstigator, int HitID, FVector Location, FRotator Rotation)
{
	if(DamageInstigator == nullptr)
	{
		return;
	}
	if(DamageInstigator->IsLocallyControlled())
	{
		return;
	}

	SpawnEffect(DamageInstigator, HitID, Location, Rotation);
}

void AFPSGameState::SpawnEffect(AFPSGameCharacter* DamageInstigator, int HitID, FVector Location,
	FRotator Rotation)
{
	const FImpact Impact = GetImpact(HitID);

	if(const UNiagaraComponent* Vfx = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Impact.Vfx, Location, Rotation, FVector(1.0f,
	1.0f, 1.0f)); Vfx != nullptr)
	{
		
	}

	if(UDecalComponent* Decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), Impact.Decal, FVector(10,10,10),
		Location, Rotation,10); Decal != nullptr)
	{
		Decal->SetFadeScreenSize(0);
	}

	UGameplayStatics::PlaySoundAtLocation(GetWorld(),Impact.ImpactSFX, Location, Rotation,0.5,1,0, ImpactSoundAttenuation);

}

void AFPSGameState::OnHit(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor,
	float Damage, const FHitResult& Hit, bool bClientSim)
{
	int HitIndex = 0;
	
	if(Hit.PhysMaterial != nullptr)
	{
		HitIndex = 	 Hit.PhysMaterial->SurfaceType;
	}
	
	if(bClientSim)
	{
		SpawnEffect(DamageInstigator, HitIndex, Hit.Location,
			UKismetMathLibrary::MakeRotFromX(Hit.ImpactNormal));
		return;
	}
	
	if(DamagedActor && DamagedActor->CanBeDamaged())
	{
		ProcessDamage(DamageInstigator, DamagedActor, Damage);
	}
	
	
	const FVector HitLocation = Hit.Location;
	const FRotator HitRotation = UKismetMathLibrary::MakeRotFromX(Hit.ImpactNormal);

	Multicast_OnHit(DamageInstigator, HitIndex, HitLocation, HitRotation);
}

void AFPSGameState::OnPlayerDeath(const AFPSGamePlayerController* Killer, AFPSGamePlayerController* Victim)
{
	Victim->PawnDied(Killer->PlayerState);

	bool bTeamWiped = true;

	AFPSPlayerState* VictimPS = Victim->GetPlayerState<AFPSPlayerState>();
	FTDMTeam VictimTeam = VictimPS->TeamID == 0 ? BlueTeam : RedTeam;

	for(int i =0 ;i	< VictimTeam.PlayerStates.Num(); i++)
	{
		AFPSGamePlayerController* PC = Cast<AFPSGamePlayerController>(VictimTeam.PlayerStates[i]->GetPlayerController());

		if(!PC->bPlayerDead)
		{
			bTeamWiped = false;
			break;
		}
	}

	if(bTeamWiped)
	{
		if(AFPSGameGameMode* GameMode = Cast<AFPSGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			GameMode->EndRound(Killer->GetPlayerState<AFPSPlayerState>()->TeamID);
			bCanInteract = false;
		}
	}
}

void AFPSGameState::StartMatch()
{
	StartingGameTimer = 3.f;
	GetWorldTimerManager().SetTimer(FMatchStartingUpdateTimerHandle, this, &AFPSGameState::UpdateMatchStartingTimer, 1.f, true);
}

void AFPSGameState::RegisterPlayerForTeam(AFPSPlayerState* PlayerState, int32 TeamID)
{
	if(TeamID == 0)
	{
		BlueTeam.PlayerStates.Add(PlayerState);

	}
	else if(TeamID == 1)
	{
		RedTeam.PlayerStates.Add(PlayerState);
	}


	AFPSGameGameMode* GameMode = Cast<AFPSGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	GameMode->OnPlayerJoinedTeam(TeamID, PlayerState->GetPlayerController());
}

void AFPSGameState::BeginPlay()
{
	Super::BeginPlay();

	RedTeam.TeamID = 1;
	BlueTeam.TeamID = 0;
}

void AFPSGameState::OnRep_MatchState()
{
	Super::OnRep_MatchState();

	if(GetWorld())
	{
		if(GetWorld()->GetFirstPlayerController())
		{
			if(GetWorld()->GetFirstPlayerController()->GetHUD())
			if(AGameHUD* GameHUD = Cast<AGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
			{
				GameHUD->OnMatchStateChanged(MatchState);
			}
		}
	}
}

void AFPSGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSGameState, StartingGameTimer);
	DOREPLIFETIME(AFPSGameState, bCanInteract);
	DOREPLIFETIME(AFPSGameState, MatchTimer);
	DOREPLIFETIME(AFPSGameState, CurrentRound);
}

void AFPSGameState::UpdateMatchStartingTimer()
{
	if(StartingGameTimer > 0)
	{
		StartingGameTimer -= 1;
	}
	else
	{
		GetWorldTimerManager().ClearTimer(FMatchStartingUpdateTimerHandle);

		if(AGameMode* GameMode = Cast<AGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			UE_LOG(LogTemp, Warning, TEXT("StartMatch"));
			SetMatchState(MatchState::InProgress);
			bCanInteract = true;
			MatchTimer = MatchLength;
			GetWorld()->GetTimerManager().SetTimer(FUpdateMatchTimerHandle, this, &AFPSGameState::UpdateMatchTimer, 1.f, true);
		}
	}
}

void AFPSGameState::UpdateMatchTimer()
{
	if(MatchTimer > 0)
	{
		MatchTimer -= 1;
	}
	else
	{
		GetWorldTimerManager().ClearTimer(FUpdateMatchTimerHandle);

		//round ended
	AFPSGameGameMode* GameMode = Cast<AFPSGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->EndRound(-1);
		bCanInteract = false;
	}
}

void AFPSGameState::ProcessDamage(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage)
{
	FDamageEvent DamageEvent { };
	DamagedActor->TakeDamage(Damage,DamageEvent , DamageInstigator->GetController(), DamageInstigator);

	if(AFPSGamePlayerController* DamagedPC = Cast<AFPSGamePlayerController>(DamagedActor->GetController()))
	{
		DamagedPC->Client_OnHit(DamageInstigator->GetActorLocation());
	}
}
