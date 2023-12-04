// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "SpawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API ASpawnPoint : public APlayerStart
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int32 TeamID;

	bool bHasPlayer;
};
