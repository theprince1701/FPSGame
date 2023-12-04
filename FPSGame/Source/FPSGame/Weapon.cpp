#include "Weapon.h"

#include "WeaponData.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

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

	ReserveMagazineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReserveMagazineMesh"));
	ReserveMagazineMesh->SetupAttachment(WeaponMesh);
	ReserveMagazineMesh->AttachToComponent(WeaponMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("SOCKET_Magazine_Reserve"));
	bReplicates = true;
}


void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeapon, ThirdPersonWeapon);
}


void AWeapon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(!Character || !Character->IsLocallyControlled())
	{
		return;
	}

	
	WeaponCurrentRecoil1 = FMath::Lerp(WeaponCurrentRecoil1, FVector::ZeroVector, WeaponData->WeaponRecoil1 * DeltaSeconds);
	WeaponCurrentRecoil3 = FMath::Lerp(WeaponCurrentRecoil3, FVector::ZeroVector, WeaponData->WeaponRecoil3 * DeltaSeconds);

	CameraCurrentRecoil1 = FMath::Lerp(CameraCurrentRecoil1, FVector::ZeroVector, WeaponData->CameraRecoil1 * DeltaSeconds);
	CameraCurrentRecoil3 = FMath::Lerp(CameraCurrentRecoil3, FVector::ZeroVector, WeaponData->CameraRecoil3 * DeltaSeconds);

	Character->RecoilComponent->SetRelativeLocation(CameraCurrentRecoil3);
	
	FRotator CamRotation(CameraCurrentRecoil1.X, CameraCurrentRecoil1.Y, CameraCurrentRecoil1.Z);
	Character->AddControllerPitchInput(CamRotation.Pitch);
	Character->AddControllerYawInput(CamRotation.Yaw);

	
	SwayX = Character->LocalHorizontalLookNonAdditive * WeaponData->SwaySpeed * DeltaSeconds;
	SwayY = Character->LocalVerticalLookNonAdditive * WeaponData->SwaySpeed * DeltaSeconds;

	const FVector TargetLocation = Character->bIsCrouched ? WeaponData->CrouchLocation : WeaponData->IdleLocation;
	DefaultLocation = FMath::Lerp(DefaultLocation, TargetLocation, DeltaSeconds * 5.f);

	const FRotator TargetRotation(SwayX * 2, SwayX , SwayY);
	DefaultRotation = FMath::Lerp(DefaultRotation, WeaponData->IdleRotation + TargetRotation , DeltaSeconds * 5.f);


	FHitResult HitResult;
	FVector StartLocation = MuzzleForward->GetComponentLocation();
	FVector EndLocation = StartLocation + MuzzleForward->GetForwardVector() * WeaponData->BarrelLength;
			
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.bReturnPhysicalMaterial = true;

	bHolstered = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation,ECollisionChannel::ECC_Visibility,QueryParams);

	if(HitResult.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("HitResult: %s"), *HitResult.GetActor()->GetName());
	}
	
}


void AWeapon::OnRep_Owner()
{
	Character = Cast<AFPSGameCharacter>(GetOwner());
	Init();
}

void AWeapon::ApplyRecoil()
{
	WeaponCurrentRecoil3 += FVector(FMath::RandRange(-WeaponData->WeaponRecoilPosition.X, WeaponData->WeaponRecoilPosition.X),
		WeaponData->WeaponRecoilPosition.Y, FMath::RandRange(-WeaponData->WeaponRecoilPosition.Z, WeaponData->WeaponRecoilPosition.Z));

	WeaponCurrentRecoil1 += FVector(WeaponData->WeaponRecoilRotation.X,FMath::RandRange(-WeaponData->WeaponRecoilRotation.Y, WeaponData->WeaponRecoilRotation.Y),
FMath::RandRange(-WeaponData->WeaponRecoilRotation.Z, WeaponData->WeaponRecoilRotation.Z));

	CameraCurrentRecoil3 += FVector(FMath::RandRange(-WeaponData->CameraRecoilPosition.X, WeaponData->CameraRecoilPosition.X),
		WeaponData->CameraRecoilPosition.Y, FMath::RandRange(-WeaponData->CameraRecoilPosition.Z, WeaponData->CameraRecoilPosition.Z));

	CameraCurrentRecoil1 += FVector(WeaponData->CameraRecoilRotation.X,FMath::RandRange(-WeaponData->CameraRecoilRotation.Y, WeaponData->CameraRecoilRotation.Y),
		FMath::RandRange(-WeaponData->CameraRecoilRotation.Z, WeaponData->CameraRecoilRotation.Z));
}

UAnimMontage* AWeapon::GetReloadAnim(bool bEmpty)
{
	return bEmpty ? WeaponData->FirstPersonPoseReloadEmpty : WeaponData->FirstPersonPoseReload;
}
