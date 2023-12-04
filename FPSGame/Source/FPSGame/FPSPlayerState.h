// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FPSPlayerState.generated.h"

UCLASS()
class FPSGAME_API AFPSPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 TeamID;


	UFUNCTION(BlueprintCallable)
	void JoinTeam(int32 TID);

	UFUNCTION(Server, Reliable)
	void Server_JoinTeam(int TID);
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnRep_Owner() override;
};
