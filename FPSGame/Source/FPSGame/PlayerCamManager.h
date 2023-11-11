// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "PlayerCamManager.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API APlayerCamManager : public APlayerCameraManager
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	float CrouchBlendDuration = .15f;

	float CrouchBlendTime;

public:
	virtual void UpdateViewTarget(FTViewTarget& OutVT, float DeltaSeconds) override;
};
