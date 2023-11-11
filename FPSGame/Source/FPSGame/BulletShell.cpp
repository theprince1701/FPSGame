// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletShell.h"

// Sets default values
ABulletShell::ABulletShell()
{
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
}

void ABulletShell::Init(FVector Velocity)
{
	BulletMesh->AddImpulse(Velocity);
}
