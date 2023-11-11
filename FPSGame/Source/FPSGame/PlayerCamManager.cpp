// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamManager.h"

#include "FPSGameCharacter.h"
#include "PlayerMovementComponent.h"
#include "Components/CapsuleComponent.h"

void APlayerCamManager::UpdateViewTarget(FTViewTarget& OutVT, float DeltaSeconds)
{
	Super::UpdateViewTarget(OutVT, DeltaSeconds);

	if(const AFPSGameCharacter* Character = Cast<AFPSGameCharacter>(GetOwningPlayerController()->GetPawn()))
	{
		const UPlayerMovementComponent* PMC = Cast<UPlayerMovementComponent>(Character->GetCharacterMovement());

		const FVector TargetCrouchOffset = FVector(
			0,
			0,
			PMC->GetCrouchedHalfHeight() - Character->GetClass()->GetDefaultObject<ACharacter>()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight());

		FVector Offset = FMath::Lerp(FVector::ZeroVector, TargetCrouchOffset, FMath::Clamp(CrouchBlendTime / CrouchBlendDuration, 0.f, 1.f));

		if(PMC->IsCrouching())
		{
			CrouchBlendTime = FMath::Clamp(CrouchBlendTime + DeltaSeconds, 0.f, CrouchBlendDuration);
			Offset -= TargetCrouchOffset;
		}
		else
		{
			CrouchBlendTime = FMath::Clamp(CrouchBlendTime - DeltaSeconds, 0.f, CrouchBlendDuration);
		}

	//	OutVT.POV.Location += Offset;

	}
}
