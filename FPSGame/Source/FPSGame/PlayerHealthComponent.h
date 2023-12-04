// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerHealthComponent.generated.h"


class AFPSGameCharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UPlayerHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPlayerHealthComponent();

	UFUNCTION(BlueprintCallable)
	void ApplyDamage(AController* Instigator, float Damage);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentHealth() const { return CurrentHealth; }
	bool GetIsDead() const { return bIsDead;}
	
protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnDeath();

	UFUNCTION()
	void OnRep_IsDead();
	UFUNCTION()
	void OnRep_CurrentHealth();
	UFUNCTION()
	void RegenHealthUpdate();
	
private:
	UPROPERTY(ReplicatedUsing=OnRep_CurrentHealth)
	float CurrentHealth;
	UPROPERTY(ReplicatedUsing=OnRep_IsDead)
	bool bIsDead;

	FTimerHandle RegenUpdateTimerHandle;

	float LastDamageTime;
	UPROPERTY()
	AFPSGameCharacter* Character;
};
