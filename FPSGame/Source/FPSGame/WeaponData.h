// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletShell.h"
#include "ThirdPersonWeapon.h"
#include "Weapon.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UWeaponData : public UPrimaryDataAsset
{
	GENERATED_BODY()


	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Actors")
	TSubclassOf<AWeapon> FPWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Actors")
	TSubclassOf<AThirdPersonWeapon> TPWeapon;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimSequence* FirstPersonPoseIdle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimSequence* FirstPersonPoseAim;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimSequence* FirstPersonPoseLoopRun;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimSequence* FirstPersonPoseLoopCrouch;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimSequence* FirstPersonPoseLoopLowered;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseFire;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseFireBolt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseUnHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseReload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseReloadEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseReloadBolt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Weapon Animations")
	UAnimMontage* FirstPersonPoseInspect;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseFire;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseFireBolt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseUnHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseReload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseReloadEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Character Animations")
	UAnimMontage* FirstPersonCharacterPoseInspect;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimSequence* ThirdPersonPoseIdle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimSequence* ThirdPersonPoseAim;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimSequence* ThirdPersonPoseLoopRun;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimSequence* ThirdPersonPoseLoopRunImpulse;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimSequence* ThirdPersonPoseLoopCrouch;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimSequence* ThirdPersonPoseLoopLowered;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseFire;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseFireBolt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Weapon Animations")
	UAnimMontage* ThirdPersonPoseFireBolt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseUnHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseReload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseReloadEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonCharacterPoseInspect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonWeaponPoseReload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonWeaponPoseReloadEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Character Animations")
	UAnimMontage* ThirdPersonWeaponPoseInspect;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FVector IdleLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FRotator IdleRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FVector CrouchLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FRotator CrouchRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FVector AimLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FRotator AimRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FVector RunLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FP Poses")
	FRotator RunRotation;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Poses")
	FVector ThirdPersonIdleLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Poses")
	FRotator ThirdPersonIdleRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Poses")
	FVector ThirdPersonAimLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TP Poses")
	FRotator ThirdPersonAimRotation;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Shell)
	TSubclassOf<ABulletShell> ShellClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Shell)
	float ShellEjectVelocity = 120;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Shell)
	float ShellDelay = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Muzzle)
	UParticleSystem* MuzzleFlash;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Muzzle)
	FVector MuzzleScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Firing)
	float FireRate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Firing)
	float Damage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Firing)
	int BulletsToFire = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Firing)
	float BulletSpread = 1.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Firing)
	float BulletSpreadAimMultiplier = 1.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Firing)
	bool bAutoFire = true;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=General)
	float BarrelLength = 5.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Crosshair)
	float CrosshairSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sway)
	float SwaySpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sway)
	float SwaySmoothing;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Aim)
	float AimSensitiveMultiplier = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponRecoil")
	float WeaponRecoil1 = 35;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponRecoil")
	float WeaponRecoil3 = 35;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponRecoil")
	float WeaponRecoilAimMultiplier = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponRecoil")
	FVector WeaponRecoilPosition;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponRecoil")
	FVector WeaponRecoilRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraRecoil")
	float CameraRecoil1 = 35;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraRecoil")
	float CameraRecoil3 = 35;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraRecoil")
	float CameraRecoilAimMultiplier = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraRecoil")
	FVector CameraRecoilPosition;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CameraRecoil")
	FVector CameraRecoilRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* FireSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* FireBoltSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* ReloadSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* ReloadEmptySound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* ReloadBoltSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* HolsterSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* UnHolsterSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* InspectSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	USoundBase* EmptySound;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ammo")
	int32 MaxAmmo = 500;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ammo")
	int32 ClipSize = 30;
};
