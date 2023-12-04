// Fill out your copyright notice in the Description page of Project Settings.


#include "FootstepAudio.h"

#include "Kismet/GameplayStatics.h"

UFootstepAudio::UFootstepAudio()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UFootstepAudio::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AFPSGameCharacter>(GetOwner());
}


// Called every frame
void UFootstepAudio::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(!Character)
	{
		return;
	}

	bool bIsMoving = Character->VerticalMovement != 0.0f || Character->HorizontalMovement != 0.0f;
	
	if(Character->IsLocallyControlled())
	{
		bIsMoving = Character->LocalVerticalMovement != 0.0f || Character->LocalHorizontalMovement != 0.0f;
	}

	FootstepInterval = Character->IsSprinting ? 0.28f : 0.39f;
	if(bIsMoving)
	{
		LastFootStepTime += DeltaTime;
		if(LastFootStepTime > FootstepInterval)
		{
			LastFootStepTime = 0.0f;

			FFootstepAudioStruct FootStep = FootstepAudios[0];

			USoundBase* Footstep = Character->IsSprinting ? FootStep.WalkAudio[FMath::RandRange(0,  FootStep.WalkAudio.Num() - 1)]
			: FootStep.RunAudio[FMath::RandRange(0,  FootStep.RunAudio.Num() - 1)];
				
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Footstep, Character->GetActorLocation(), 1.0f, 1.0f, 0.0f, Attenuation);

			CurrentAudioIndex++;

			if(CurrentAudioIndex >= FootstepAudios[0].WalkAudio.Num())
			{
				CurrentAudioIndex = 0;
			}
		}
	}
}

void UFootstepAudio::PlayFootstepAudio()
{
	FFootstepAudioStruct FootStep = FootstepAudios[0];

	USoundBase* Footstep = FootStep.WalkAudio[FMath::RandRange(0,  FootStep.WalkAudio.Num() - 1)];
				
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), Footstep, Character->GetActorLocation(), 0.3f, 1.0f, 0.0f, Attenuation);
}

