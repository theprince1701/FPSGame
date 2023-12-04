// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "WeaponController.generated.h"



class AFPSGameCharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UWeaponController : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly)
	USoundAttenuation* ShootSoundAttenuation;

	UPROPERTY(EditDefaultsOnly)
	float ProjectileSpawnOffset;
	
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
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCurrentAmmo() const { return CurrentAmmo; }

	UPROPERTY()
	int32 CurrentAmmo;

protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION()
	void OnRep_FireCount();
	UFUNCTION()
	void OnRep_IsAiming();
	UFUNCTION()
	void OnRep_IsInspecting();
	UFUNCTION()
	void OnRep_IsReloading();
	
	void Fire();

private:
	UFUNCTION(Server, Reliable)
	void Server_Fire();
	UFUNCTION(Server, Reliable)
	void Server_SetAim(bool bIsAim);
	UFUNCTION(Server, Reliable)
	void Server_SetInspect(bool bIsInspect);
	UFUNCTION(Server, Reliable)
	void Server_SetReload(bool bIsReload);
	
	UFUNCTION(Client, Reliable)
	void Client_UpdateAmmo(uint32 ServerAmmo);
	UFUNCTION(Client, Reliable)
	void Client_AddAmmo(uint32 AmmoToAdd);
	
	UPROPERTY(ReplicatedUsing=OnRep_FireCount)
	uint32 FireCount;
	UPROPERTY(ReplicatedUsing=OnRep_IsAiming)
	bool bIsAiming;
	UPROPERTY(ReplicatedUsing=OnRep_IsReloading)
	bool bIsReloading;
	UPROPERTY(ReplicatedUsing=OnRep_IsInspecting)
	bool bIsInspecting;
	UPROPERTY()
	uint32 CurrentAmmoInMagazine;

	void OnReloadEnd();
	void OnInspectEnd();
	
	//# of unprocessed server requests for ammo
	int32 AmmoSequence = 0;

	bool bIsFiring;

	float LastAttackTime;
	UPROPERTY()
	AFPSGameCharacter* Character;

	FTimerHandle FireTimerHandle;
	FTimerHandle ReloadTimerHandle;
	FTimerHandle InspectTimerHandle;
};
