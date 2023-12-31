// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerHealthComponent.h"
#include "WeaponController.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "FPSGameCharacter.generated.h"

class AFPSGameState;
class AFPSGamePlayerController;
class UWeaponManager;
class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AFPSGameCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneComponent* LeanComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* ReloadAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* InspectAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* LeanLeft;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* LeanRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SwapWeaponsAction;

	UPROPERTY(EditAnywhere)
	float LeanSpeed = 0;
	UPROPERTY(EditAnywhere)
	float LeanAmount = 15.f;
	
	float ServerHorizontalLook;
	FRotator CurrentLeanRotation;
public:
	AFPSGameCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Replicated, BlueprintReadOnly)
	float VerticalMovement;
	UPROPERTY(Replicated, BlueprintReadOnly)
	float HorizontalMovement;
	UPROPERTY(Replicated, BlueprintReadOnly)
	float VerticalLook;
	UPROPERTY(Replicated, BlueprintReadOnly)
	float HorizontalLook;
	
	UPROPERTY(Replicated, BlueprintReadOnly)
	bool IsSliding;
	UPROPERTY(Replicated, BlueprintReadOnly)
	float SlideTimer;
	UPROPERTY(Replicated, BlueprintReadOnly)
	bool IsSprinting;
	UPROPERTY(Replicated, BlueprintReadOnly)
	FRotator CameraRot;

	UPROPERTY(BlueprintReadOnly)
	float LocalHorizontalLookSmoothed;

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleOutline(bool bEnable);

	UPROPERTY(BlueprintReadOnly)
	float LocalVerticalMovement;
	UPROPERTY(BlueprintReadOnly)
	float LocalHorizontalMovement;
	UPROPERTY(BlueprintReadOnly)
	float LocalHorizontalLook;
	UPROPERTY(BlueprintReadOnly)
	float LocalVerticalLook;
	UPROPERTY(BlueprintReadOnly)
	float LocalHorizontalLookNonAdditive;
	UPROPERTY(BlueprintReadOnly)
	float LocalVerticalLookNonAdditive;
	
protected:
	virtual void BeginPlay() override;

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Movement)
	class UPlayerMovementComponent* PlayerMovementComponent;

	UPROPERTY()
	AFPSGamePlayerController* PC;
	UPROPERTY()
	AFPSGameState* FPSGameState;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	UWeaponController* WeaponController;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	UWeaponManager* WeaponManager;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Health, meta = (AllowPrivateAccess = "true"))
	UPlayerHealthComponent* HealthComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=Recoil)
	USceneComponent* RecoilComponent;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnRep_Controller() override;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION(Server, Unreliable)
	void Server_SetInput(float VerticalMove, float HorizontalMove, float VertLook, float HorLook, FRotator CameraRotation);

private:
	void SprintPressed();
	void SprintReleased();

	void FirePressed();
	void FireReleased();

	void ReloadPressed();
	void InspectPressed();
	
	void AimPressed();
	void AimReleased();

	void OnLeanLeftPressed();
	void OnLeanRightPressed();
	void ResetLean();
	
	void CrouchPressed();
	void CrouchReleased();

	void StopMovement();

	void OnSwapWeaponsPressed();

public:
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	FCollisionQueryParams GetIgnoreCharacterParams() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSlideStart();
	UFUNCTION(BlueprintImplementableEvent)
	void OnSlideEnd();
};

