// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CrosshairWidget.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* PlayerHUD;
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* DeathWidget;
	UPROPERTY(BlueprintReadWrite)
	UCrosshairWidget* CrossHairWidget;


	UFUNCTION(BlueprintImplementableEvent)
	void OnKill(const FString& PlayerName);
	UFUNCTION(BlueprintImplementableEvent)
	void OnHit(AActor* HitActor, FVector Location);
	UFUNCTION(BlueprintImplementableEvent)
	void TogglePauseUI(bool bShow);
	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchStateChanged(FName NewState);
	UFUNCTION(BlueprintImplementableEvent)
	void EndRound(int32 Winner);
};
