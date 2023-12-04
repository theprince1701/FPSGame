// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletShell.h"
#include "FPSGameCharacter.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Weapon.generated.h"

class AThirdPersonWeapon;
class UWeaponData;
UCLASS()
class FPSGAME_API AWeapon : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* WeaponMesh;


public:	
	AWeapon();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* AttackForward;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* MuzzleForward;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ShellForward;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ReserveMagazineMesh;

	UPROPERTY(BlueprintReadOnly)
	FVector WeaponCurrentRecoil1;
	UPROPERTY(BlueprintReadOnly)
	FVector WeaponCurrentRecoil3;
	UPROPERTY(BlueprintReadOnly)
	FVector CameraCurrentRecoil1;
	UPROPERTY(BlueprintReadOnly)
	FVector CameraCurrentRecoil3;
	UPROPERTY(BlueprintReadOnly)
	bool bHolstered;
	UPROPERTY(Replicated)
	AThirdPersonWeapon* ThirdPersonWeapon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeaponData* WeaponData;
	
	UPROPERTY(BlueprintReadOnly)
	FVector DefaultLocation;
	UPROPERTY(BlueprintReadOnly)
	FRotator DefaultRotation;
	UPROPERTY(BlueprintReadOnly)
	AFPSGameCharacter* Character;

protected:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
	
	
	float SwayX;
	float SwayY;
	
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnRep_Owner() override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FireLocal();
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadLocal();
	UFUNCTION(BlueprintImplementableEvent)
	void EndReloadLocal();
	UFUNCTION(BlueprintImplementableEvent)
	void InspectLocal();
	UFUNCTION(BlueprintImplementableEvent)
	void Init();
	UFUNCTION(BlueprintImplementableEvent)
	void Show();
	UFUNCTION(BlueprintImplementableEvent)
	void Hide();

	UFUNCTION(BlueprintCallable)
	void ApplyRecoil();

	UAnimMontage* GetReloadAnim(bool bEmpty);
};

