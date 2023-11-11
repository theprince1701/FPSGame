// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "Weapon.h"
#include "Components/ActorComponent.h"
#include "WeaponManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UWeaponManager : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AWeapon>> WeaponReferences;
	
public:	
	UWeaponManager();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AWeapon* GetCurrentWeapon() const { return CurrentWeapon; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY() AFPSGameCharacter* Character;
	UPROPERTY() AWeapon* CurrentWeapon;
};
