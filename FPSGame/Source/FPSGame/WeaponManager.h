// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "ItemData.h"
#include "ThirdPersonWeapon.h"
#include "Weapon.h"
#include "Components/ActorComponent.h"
#include "WeaponManager.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UWeaponManager : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<UWeaponData*> WeaponReferences;

public:	
	UWeaponManager();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AWeapon* GetCurrentWeapon() const { return CurrentWeapon; }
	
	UPROPERTY(ReplicatedUsing=OnRep_CurrentWeapon)
	AWeapon* CurrentWeapon;

	int CurrentWeaponIndex;

	UPROPERTY(ReplicatedUsing=OnRep_Weapons)
	TArray<AWeapon*> Weapons;

	virtual void IncrementCurrentWeapon();
	virtual void DecrementCurrentWeapon();
	virtual void SetWeapon(UWeaponData* WeaponData);
	bool bSwitching;
	
protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;

	UFUNCTION()
	virtual void OnRep_CurrentWeapon();
	UFUNCTION()
	virtual void OnRep_Weapons();
	virtual void InitWeapons();

	
	virtual void SetCurrentWeapon(int WeaponIndex);
	virtual void SwapWeapons(int NewIndex);

	UFUNCTION(Server, Reliable)
	void Server_SetCurrentWeapon(AWeapon* NewWeapon);
private:
	FTimerHandle HideCurrentWeaponTimerHandle;
	FTimerHandle ShowNewWeaponTimerHandle;

	void OnCurrentWeaponHidden(AWeapon* NewWeapon);
	void OnNewWeaponShowed(AWeapon* NewWeapon);
	
	UPROPERTY()
	AFPSGameCharacter* Character;
};
