// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "Components/ActorComponent.h"
#include "FootstepAudio.generated.h"

USTRUCT(BlueprintType)
struct FFootstepAudioStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int SurfaceType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<USoundBase*> WalkAudio;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<USoundBase*> RunAudio;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UFootstepAudio : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	float FootstepInterval;
	UPROPERTY(EditDefaultsOnly)
	TArray<FFootstepAudioStruct> FootstepAudios;
	UPROPERTY(EditDefaultsOnly)
	USoundAttenuation* Attenuation;
public:	
	UFootstepAudio();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	AFPSGameCharacter* Character;

	FTimerHandle FootstepTimerHandle;
	int CurrentAudioIndex;
	float LastFootStepTime;
	bool bPlayingAudio;

	void PlayFootstepAudio();
};
