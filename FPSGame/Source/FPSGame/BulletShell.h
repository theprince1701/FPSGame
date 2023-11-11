// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletShell.generated.h"

UCLASS()
class FPSGAME_API ABulletShell : public AActor
{
	GENERATED_BODY()

public:	
	ABulletShell();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UStaticMeshComponent* BulletMesh;
	
	UFUNCTION(BlueprintCallable)
	void Init(FVector Velocity);
};
