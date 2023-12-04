// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerState.h"

#include "FPSGameState.h"
#include "Net/UnrealNetwork.h"

void AFPSPlayerState::JoinTeam(int32 TID)
{

	Server_JoinTeam(TID);
}

void AFPSPlayerState::Server_JoinTeam_Implementation(int TID)
{
	AFPSGameState* GS = GetWorld()->GetGameState<AFPSGameState>();

	if(GS == nullptr)
	{
		return;
	}

	TeamID = TID;
	GS->RegisterPlayerForTeam(this, TeamID);
}

void AFPSPlayerState::OnRep_Owner()
{
	Super::OnRep_Owner();

	UE_LOG(LogTemp, Warning, TEXT("OnRep_Owner"));
}




void AFPSPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSPlayerState, TeamID);
}
