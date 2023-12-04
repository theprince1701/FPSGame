// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	ProximityTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ProximityTrigger"));
	ProximityTrigger->SetupAttachment(RootComponent);
	
	bIsDoorOpen = false;
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
		
	ProximityTrigger->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnPlayerEnterProximity);
	ProximityTrigger->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnPlayerLeaveProximity);

}

void ADoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	FRotator TargetAngle = bIsDoorOpen ? FRotator(0.0f, 90.0f, 0.0f) : FRotator(0.0f, 0.0f, 0.0f);
	FRotator SmoothedAngle = FMath::RInterpTo(DoorMesh->GetRelativeRotation(), TargetAngle, DeltaSeconds, 2.0f);

	DoorMesh->SetRelativeRotation(SmoothedAngle);

}

void ADoor::OnPlayerEnterProximity(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		bIsDoorOpen = true;
	} 
}


void ADoor::OnPlayerLeaveProximity(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor )
	{
		bIsDoorOpen = false;
	}
}
