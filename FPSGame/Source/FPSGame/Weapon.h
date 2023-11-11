// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletShell.h"
#include "FPSGameCharacter.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Weapon.generated.h"

UCLASS()
class FPSGAME_API AWeapon : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* AttackForward;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* MuzzleForward;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ShellForward;

public:	
	AWeapon();

	virtual void InitWeapon(AFPSGameCharacter* Player);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimSequence* FirstPersonPoseIdle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimSequence* FirstPersonPoseAim;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimSequence* FirstPersonPoseLoopRun;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimSequence* FirstPersonPoseLoopCrouch;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimSequence* FirstPersonPoseLoopLowered;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimMontage* FirstPersonPoseFire;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimMontage* FirstPersonPoseHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimMontage* FirstPersonPoseUnHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimMontage* FirstPersonPoseReload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimMontage* FirstPersonPoseReloadEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon Animations")
	UAnimMontage* FirstPersonPoseInspect;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Animations")
	UAnimMontage* FirstPersonCharacterPoseFire;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Animations")
	UAnimMontage* FirstPersonCharacterPoseHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Animations")
	UAnimMontage* FirstPersonCharacterPoseUnHolster;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Animations")
	UAnimMontage* FirstPersonCharacterPoseReload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Animations")
	UAnimMontage* FirstPersonCharacterPoseReloadEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Animations")
	UAnimMontage* FirstPersonCharacterPoseInspect;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FVector IdleLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FRotator IdleRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FVector CrouchLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FRotator CrouchRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FVector AimLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FRotator AimRotation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FVector RunLocation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Poses)
	FRotator RunRotation;

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Crosshair)
	float CrosshairSize;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sway)
	float SwaySpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Sway)
	float SwaySmoothing;
	
	UPROPERTY(BlueprintReadOnly)
	FVector DefaultLocation;
	UPROPERTY(BlueprintReadOnly)
	FRotator DefaultRotation;

protected:
	UPROPERTY(BlueprintReadOnly)
	AFPSGameCharacter* Character;

	float SwayX;
	float SwayY;
	
	virtual void Tick(float DeltaSeconds) override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FireLocal();
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadLocal();
	UFUNCTION(BlueprintImplementableEvent)
	void InspectLocal();
};

