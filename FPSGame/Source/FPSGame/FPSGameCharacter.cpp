#include "FPSGameCharacter.h"
#include "FPSGameProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FPSGameGameMode.h"
#include "FPSGamePlayerController.h"
#include "FPSGameState.h"
#include "GameHUD.h"
#include "InputActionValue.h"
#include "PlayerMovementComponent.h"
#include "WeaponManager.h"
#include "Engine/LocalPlayer.h"
#include "Net/UnrealNetwork.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AFPSGameCharacter::AFPSGameCharacter(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayerMovementComponent>(ACharacter::CharacterMovementComponentName))

{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	HealthComponent = CreateDefaultSubobject<UPlayerHealthComponent>(TEXT("HealthComponent"));
	WeaponManager = CreateDefaultSubobject<UWeaponManager>(TEXT("WeaponManager"));
	WeaponController = CreateDefaultSubobject<UWeaponController>(TEXT("WeaponController"));

	LeanComponent = CreateDefaultSubobject<USceneComponent>(TEXT("LeanComponent"));
	LeanComponent->SetupAttachment(GetCapsuleComponent());
	RecoilComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RecoilComponent"));
	RecoilComponent->SetupAttachment(LeanComponent);
	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(RecoilComponent);
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	PrimaryActorTick.bCanEverTick = true;
}

void AFPSGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}


	PC = Cast<AFPSGamePlayerController>(GetController());
	FPSGameState =	 Cast<AFPSGameState>(GetWorld()->GetGameState());
	PlayerMovementComponent = Cast<UPlayerMovementComponent>(GetCharacterMovement());

	if(IsLocallyControlled())
	{
		AFPSGamePlayerController* LocalPC = Cast<AFPSGamePlayerController>(GetController());
		if(const AGameHUD* GameHUD = Cast<AGameHUD>(LocalPC->GetHUD()))
		{
			GameHUD->PlayerHUD->AddToViewport();
			GameHUD->CrossHairWidget->AddToViewport();
			GameHUD->DeathWidget->RemoveFromParent();
		}
	}
}

void AFPSGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSGameCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::None, this, &AFPSGameCharacter::StopMovement);
		
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSGameCharacter::Look);

		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AFPSGameCharacter::CrouchPressed);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AFPSGameCharacter::CrouchReleased);

		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AFPSGameCharacter::SprintPressed);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AFPSGameCharacter::SprintReleased);
		
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Started, this, &AFPSGameCharacter::AimPressed);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AFPSGameCharacter::AimReleased);

		EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Triggered, this, &AFPSGameCharacter::ReloadPressed);
		EnhancedInputComponent->BindAction(InspectAction, ETriggerEvent::Triggered, this, &AFPSGameCharacter::InspectPressed);
		EnhancedInputComponent->BindAction(SwapWeaponsAction, ETriggerEvent::Triggered, this, &AFPSGameCharacter::OnSwapWeaponsPressed);

		
		EnhancedInputComponent->BindAction(LeanLeft, ETriggerEvent::Started, this, &AFPSGameCharacter::OnLeanLeftPressed);
		EnhancedInputComponent->BindAction(LeanRight, ETriggerEvent::Started, this, &AFPSGameCharacter::OnLeanRightPressed);
		EnhancedInputComponent->BindAction(LeanRight, ETriggerEvent::Completed, this, &AFPSGameCharacter::ResetLean);
		EnhancedInputComponent->BindAction(LeanLeft, ETriggerEvent::Completed, this, &AFPSGameCharacter::ResetLean);


		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AFPSGameCharacter::FirePressed);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AFPSGameCharacter::FireReleased);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AFPSGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSGameCharacter, VerticalMovement);
	DOREPLIFETIME(AFPSGameCharacter, HorizontalMovement);
	DOREPLIFETIME(AFPSGameCharacter, VerticalLook);
	DOREPLIFETIME(AFPSGameCharacter, HorizontalLook);
	DOREPLIFETIME(AFPSGameCharacter, IsSliding);
	DOREPLIFETIME(AFPSGameCharacter, IsSprinting);
	DOREPLIFETIME(AFPSGameCharacter, SlideTimer);
	DOREPLIFETIME(AFPSGameCharacter, CameraRot);
}

void AFPSGameCharacter::SprintPressed()
{
	if(PC && PC->bPaused || !FPSGameState->bCanInteract)
	{
		return;
	}
	
	PlayerMovementComponent->SprintPressed();
}

void AFPSGameCharacter::SprintReleased()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	PlayerMovementComponent->SprintReleased();
}

void AFPSGameCharacter::FirePressed()
{
	if(PC && PC->bPaused || !FPSGameState->bCanInteract)
	{
		return;
	}
	
	WeaponController->FirePressed();
}

void AFPSGameCharacter::FireReleased()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	WeaponController->FireReleased();
}

void AFPSGameCharacter::ReloadPressed()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	WeaponController->ReloadPressed();
}

void AFPSGameCharacter::InspectPressed()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	WeaponController->InspectPressed();
}

void AFPSGameCharacter::AimPressed()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	WeaponController->AimPressed();
}

void AFPSGameCharacter::AimReleased()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	WeaponController->AimReleased();
}

void AFPSGameCharacter::OnLeanLeftPressed()
{
	LocalHorizontalLook  = -90;

}

void AFPSGameCharacter::OnLeanRightPressed()
{
	LocalHorizontalLook = 90;
}

void AFPSGameCharacter::ResetLean()
{
	LocalHorizontalLook = 0;
}

void AFPSGameCharacter::CrouchPressed()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	PlayerMovementComponent->CrouchPressed();
}

void AFPSGameCharacter::CrouchReleased()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
	PlayerMovementComponent->CrouchReleased();
}

void AFPSGameCharacter::StopMovement()
{
	LocalHorizontalMovement = 0.0f;
	LocalVerticalMovement = 0.0f;
}

void AFPSGameCharacter::OnSwapWeaponsPressed()
{
	if(PC && PC->bPaused)
	{
		return;
	}
	
//	WeaponManager->IncrementCurrentWeapon();
}

FCollisionQueryParams AFPSGameCharacter::GetIgnoreCharacterParams() const
{
	FCollisionQueryParams Params;
 
	TArray<AActor*> CharacterChildren;
	GetAllChildActors(CharacterChildren);
	Params.AddIgnoredActors(CharacterChildren);
	Params.AddIgnoredActor(this);

	return Params;
}

void AFPSGameCharacter::Server_SetInput_Implementation(float VerticalMove, float HorizontalMove, float VertLook,
                                                       float HorLook,FRotator CameraRotation)
{
	VerticalMovement = VerticalMove;
	HorizontalMovement = HorizontalMove;

	VerticalLook = VertLook;
	ServerHorizontalLook = HorLook;
	CameraRot = CameraRotation;
}


void AFPSGameCharacter::Move(const FInputActionValue& Value)
{
	if(PC && PC->bPaused)
	{
		return;
	}

	if(IsSliding || !FPSGameState->bCanInteract)
	{
		StopMovement();
		return;
	}
	
	
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		LocalVerticalMovement = MovementVector.Y;
		LocalHorizontalMovement = MovementVector.X;
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AFPSGameCharacter::Look(const FInputActionValue& Value)
{
	if(!PC)
	{
		PC =	Cast<AFPSGamePlayerController>(GetController());
	}
	if(PC && PC->bPaused)
	{
		return;
	}

	
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		float Sensitvity = (WeaponController->GetIsAiming() ? 0.5f : 1.0f) * PC->MouseSensitivity;
		LocalVerticalLook -= LookAxisVector.Y * 3.0f;
		LocalVerticalLook = FMath::Clamp(LocalVerticalLook, -90, 90);

		LocalVerticalLookNonAdditive = LookAxisVector.Y;
		LocalHorizontalLookNonAdditive = LookAxisVector.X;

		AddControllerYawInput(LookAxisVector.X * Sensitvity);
		AddControllerPitchInput(LookAxisVector.Y * Sensitvity);
	}
}

void AFPSGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(IsLocallyControlled())
	{
		FRotator CameraRotation = FirstPersonCameraComponent->GetComponentRotation();
	//	UE_LOG(LogTemp, Warning, TEXT("Camera Rotation: %s"), *CameraRotation.ToString());
		Server_SetInput(LocalVerticalMovement, LocalHorizontalMovement, CameraRotation.Pitch, LocalHorizontalLook, FirstPersonCameraComponent->GetComponentRotation());
		/*/
		LocalHorizontalLookSmoothed = FMath::Lerp(LocalHorizontalLookSmoothed, LocalHorizontalLook, DeltaSeconds *LeanSpeed);

		FRotator LeanRotation = FRotator(0, 0, LocalHorizontalLookSmoothed * LeanAmount);
		CurrentLeanRotation = FMath::Lerp(CurrentLeanRotation, LeanRotation, DeltaSeconds *LeanSpeed);
		LeanComponent->SetRelativeRotation(CurrentLeanRotation);
		/*/
	}

	if(HasAuthority())
	{
		HorizontalLook = FMath::Lerp(HorizontalLook, ServerHorizontalLook, DeltaSeconds * LeanSpeed);
	}
}

void AFPSGameCharacter::OnRep_Controller()
{
	Super::OnRep_Controller();

	if(IsLocallyControlled())
	{
		AFPSGamePlayerController* LocalPC = Cast<AFPSGamePlayerController>(GetController());
		if(const AGameHUD* GameHUD = Cast<AGameHUD>(LocalPC->GetHUD()))
		{
			GameHUD->PlayerHUD->AddToViewport();
			GameHUD->CrossHairWidget->AddToViewport();
			GameHUD->DeathWidget->RemoveFromParent();
		}
	}
}

