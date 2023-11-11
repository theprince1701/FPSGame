#include "Weapon.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	
	AttackForward = CreateDefaultSubobject<UArrowComponent>(TEXT("AttackForward"));
	AttackForward->SetupAttachment(WeaponMesh);
	
	MuzzleForward = CreateDefaultSubobject<UArrowComponent>(TEXT("MuzzleForward"));
	MuzzleForward->SetupAttachment(WeaponMesh);

	ShellForward = CreateDefaultSubobject<UArrowComponent>(TEXT("ShellForward"));
	ShellForward->SetupAttachment(WeaponMesh);
}

void AWeapon::InitWeapon(AFPSGameCharacter* Player)
{
	Character = Player;
}

void AWeapon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(!Character || !Character->IsLocallyControlled())
	{
		return;
	}

	SwayX = Character->LocalHorizontalLook * SwaySpeed * DeltaSeconds;
	SwayY = Character->LocalVerticalLook * SwaySpeed * DeltaSeconds;

	const FVector TargetLocation = Character->bIsCrouched ? CrouchLocation : IdleLocation;
	DefaultLocation = FMath::Lerp(DefaultLocation, TargetLocation, DeltaSeconds * 5.f);

	const FRotator TargetRotation(SwayX * 2, SwayX , SwayY);
	DefaultRotation = FMath::Lerp(DefaultRotation, TargetRotation, DeltaSeconds * 5.f);
}
