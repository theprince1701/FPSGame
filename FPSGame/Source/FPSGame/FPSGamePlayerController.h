// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "FPSPlayerState.h"
#include "GameFramework/PlayerController.h"
#include "FPSGamePlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class FPSGAME_API AFPSGamePlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpectatorPawn> SpectatorPawnSubclass;
	UPROPERTY(EditDefaultsOnly)
	float RespawnTimer = 5.f;

	
public:
	AFPSGamePlayerController();
	UPROPERTY(Replicated, BlueprintReadOnly)
	float CurrentRespawnTimer;
	UPROPERTY(BlueprintReadWrite)
	float MouseSensitivity;

	bool bPlayerDead;
	bool bPaused;

	virtual void PawnDied(APlayerState* Killer);
	virtual void OnHit(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage, const FHitResult& Hit);
	
	UFUNCTION(Client, Reliable)                  
	void Client_OnKill(APlayerState* Victim);    
	UFUNCTION(Client, Reliable)
	void Client_OnHit(FVector Location);
	UFUNCTION(Client, Reliable)
	void Client_OnEndRound(int32 Winner);
	
	UPROPERTY(BlueprintReadOnly)
	float FPS;
	UPROPERTY(BlueprintReadOnly)
	float Ping;
	UPROPERTY(BlueprintReadOnly)
	float PacketLoss;

	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;
	
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void RespawnTick();
	virtual void OnRep_Pawn() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void OnRep_PlayerState() override;

	UFUNCTION(Server, Reliable)
	void Server_OnHit(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage, const FHitResult& Hit);
	UFUNCTION(Reliable, Client)
	void Client_OnDeath(APlayerState* Killer);
	UFUNCTION(Reliable, Server)
	void Server_SetName(const FString& PlayerName);
	
	UFUNCTION(Reliable, Client)
	void Client_Respawn();

	UFUNCTION(BlueprintCallable)
	virtual void TogglePaused();

private:
	FTimerHandle RespawnTimerHandle;
	UPROPERTY()
	AActor* PlayerPawnActor;

};
