#include "FPSGameCharacter.h"
#include "FPSGameProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
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

	WeaponManager = CreateDefaultSubobject<UWeaponManager>(TEXT("WeaponManager"));
	WeaponController = CreateDefaultSubobject<UWeaponController>(TEXT("WeaponController"));

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
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
	
	PlayerMovementComponent = Cast<UPlayerMovementComponent>(GetCharacterMovement());
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
	DOREPLIFETIME(AFPSGameCharacter, IsSliding);
	DOREPLIFETIME(AFPSGameCharacter, IsSprinting);
	DOREPLIFETIME(AFPSGameCharacter, SlideTimer);
}

void AFPSGameCharacter::SprintPressed()
{
	PlayerMovementComponent->SprintPressed();
}

void AFPSGameCharacter::SprintReleased()
{
	PlayerMovementComponent->SprintReleased();
}

void AFPSGameCharacter::FirePressed()
{
	WeaponController->FirePressed();
}

void AFPSGameCharacter::FireReleased()
{
	WeaponController->FireReleased();
}

void AFPSGameCharacter::ReloadPressed()
{
}

void AFPSGameCharacter::InspectPressed()
{
}

void AFPSGameCharacter::AimPressed()
{
	WeaponController->AimPressed();
}

void AFPSGameCharacter::AimReleased()
{
	WeaponController->AimReleased();
}

void AFPSGameCharacter::CrouchPressed()
{
	PlayerMovementComponent->CrouchPressed();
}

void AFPSGameCharacter::CrouchReleased()
{
	PlayerMovementComponent->CrouchReleased();
}

void AFPSGameCharacter::StopMovement()
{
	LocalHorizontalMovement = 0.0f;
	LocalVerticalMovement = 0.0f;
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
                                                       float HorLook)
{
	VerticalMovement =VerticalMove;
	HorizontalMovement =HorizontalMove;

	VerticalLook = VertLook;
	HorizontalLook = HorLook;
}


void AFPSGameCharacter::Move(const FInputActionValue& Value)
{
	if(IsSliding)
	{
		StopMovement();
		return;
	}
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		LocalHorizontalMovement  =MovementVector.X;
		LocalVerticalMovement = MovementVector.Y;
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AFPSGameCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		LocalHorizontalLook = LookAxisVector.X;
		LocalVerticalLook = LookAxisVector.Y;
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AFPSGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(IsLocallyControlled())
	{
		Server_SetInput(LocalVerticalMovement, LocalHorizontalMovement, LocalVerticalLook, LocalHorizontalLook);
	}
}

