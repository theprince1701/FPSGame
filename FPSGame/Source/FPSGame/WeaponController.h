// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponController.generated.h"

class AFPSGameCharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UWeaponController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponController();

	virtual void FirePressed();
	virtual void FireReleased();
	virtual void AimPressed();
	virtual void AimReleased();
	virtual void ReloadPressed();
	virtual void InspectPressed();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetIsAiming() const { return bIsAiming; }

protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnRep_FireCount();
	UFUNCTION()
	void OnRep_IsAiming();

	void Fire();

private:
	UFUNCTION(Server, Reliable)
	void Server_Fire();
	UFUNCTION(Server, Reliable)
	void Server_SetAim(bool bIsAim);

	UPROPERTY(ReplicatedUsing=OnRep_FireCount)
	uint32 FireCount;
	UPROPERTY(ReplicatedUsing=OnRep_IsAiming)
	bool bIsAiming;

	bool bIsFiring;

	UPROPERTY()
	AFPSGameCharacter* Character;

	FTimerHandle FireTimerHandle;
};
