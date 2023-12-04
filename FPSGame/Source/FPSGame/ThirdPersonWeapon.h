#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "ThirdPersonWeapon.generated.h"

class UWeaponData;
UCLASS()
class FPSGAME_API AThirdPersonWeapon : public AActor
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
	AThirdPersonWeapon();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector DefaultSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FRotator DefaultSpawnRotation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeaponData* WeaponData;
	UPROPERTY(BlueprintReadOnly)
	AFPSGameCharacter* Character;
	void Init(AFPSGameCharacter* Player);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFire();
	UFUNCTION(BlueprintImplementableEvent)
	void OnReload(bool bEmpty);
	UFUNCTION(BlueprintImplementableEvent)
	void OnInspect();
	
protected:
	virtual void BeginPlay() override;
	virtual void OnRep_Owner() override;
	virtual bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const override;
	UFUNCTION(BlueprintImplementableEvent)
	void InitBP();

private:

};
