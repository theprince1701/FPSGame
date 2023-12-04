// Fill out your copyright notice in the Description page of Project Settings.


#include "Spectator.h"

void ASpectator::Destroyed()
{
	Super::Destroyed();

	if(Target)
	{
		Target->GetMesh()->bRenderCustomDepth = false;
	}
}

void ASpectator::Init(AFPSGameCharacter* Killer, FVector const& InLocation, FRotator const& InRotation)
{
	Killer->GetMesh()->bRenderCustomDepth = true;
	Target = Killer;
}
