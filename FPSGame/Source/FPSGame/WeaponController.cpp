

#include "WeaponController.h"

#include <complex>

#include "FPSGameCharacter.h"
#include "GameHUD.h"
#include "WeaponData.h"
#include "WeaponManager.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

UWeaponController::UWeaponController()
{
	//SetIsReplicated(true);
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponController::FirePressed()
{
	if(!Character->WeaponManager->GetCurrentWeapon() || Character->IsSprinting)
	{
		bIsFiring = false;
		return;
	}

	

	if(CurrentAmmo > 0)
	{
		bIsFiring = true;
	}
}

void UWeaponController::FireReleased()
{
	bIsFiring = false;
}


void UWeaponController::Fire()
{
	if(!bIsFiring || CurrentAmmo <= 0 || bIsReloading)
	{
		GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
		return;
	}

	if(bIsInspecting)
	{
		bIsInspecting = false;
		Server_SetInspect(false);
	}
	
	Character->WeaponManager->GetCurrentWeapon()->FireLocal();
	CurrentAmmo--;

	if(AGameHUD* HUD = Cast<AGameHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD()))
	{
		HUD->CrossHairWidget->OnFire();
	}

	if(!Character->HasAuthority())
	{
		AmmoSequence++;
	}
	for(int i = 0; i < Character->WeaponManager->GetCurrentWeapon()->WeaponData->BulletsToFire; i++)
	{
		const FVector Location = Character->GetFirstPersonCameraComponent()->GetComponentLocation()
		+ Character->GetFirstPersonCameraComponent()->GetForwardVector() * ProjectileSpawnOffset;
		
		const float WeaponSpread = bIsAiming ?
			Character->WeaponManager->GetCurrentWeapon()->WeaponData->BulletSpread / Character->WeaponManager->GetCurrentWeapon()->WeaponData->BulletSpreadAimMultiplier :
		Character->WeaponManager->GetCurrentWeapon()->WeaponData->BulletSpread;

		FRotator Rotation =   Character->GetFirstPersonCameraComponent()->GetComponentRotation()
		+ FRotator(FMath::RandRange(-WeaponSpread, WeaponSpread),
			FMath::RandRange(-WeaponSpread, WeaponSpread),
			FMath::RandRange(-WeaponSpread, WeaponSpread));
		
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		if(AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation, SpawnParameters))
		{
			Projectile->Init(Character->WeaponManager->GetCurrentWeapon()->WeaponData);
			Projectile->SetInstigator(Character);
			Projectile->SetOwner(Character);
		}
	
		Server_Fire();
	}
}

void UWeaponController::OnRep_FireCount()
{
	if(!Character)
	{
		return;
	}
	
	if(Character->IsLocallyControlled())
	{
		return;
	}
	
	if(Character->WeaponManager->GetCurrentWeapon()->ThirdPersonWeapon)
	{
		Character->WeaponManager->GetCurrentWeapon()->ThirdPersonWeapon->OnFire();
	}

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), Character->WeaponManager->GetCurrentWeapon()->WeaponData->FireSound,
			Character->GetFirstPersonCameraComponent()->GetComponentLocation(),
			1, 1, 0, ShootSoundAttenuation);
}

void UWeaponController::Server_Fire_Implementation()
{
	FireCount++;
	OnRep_FireCount();

	if(!Character->IsLocallyControlled())
	{
		CurrentAmmo--;
	}
	
	Client_UpdateAmmo(CurrentAmmo);
}


void UWeaponController::AimPressed()
{
	bIsAiming = true;
	Server_SetAim(true);
}

void UWeaponController::AimReleased()
{
	bIsAiming = false;
	Server_SetAim(false);
}

void UWeaponController::Server_SetAim_Implementation(bool bIsAim)
{
	bIsAiming  = bIsAim;
}


void UWeaponController::Client_AddAmmo_Implementation(uint32 AmmoToAdd)
{
	if(Character->HasAuthority())
	{
		return;
	}
	
	CurrentAmmo = FMath::Clamp(CurrentAmmo + AmmoToAdd, 0, Character->WeaponManager->GetCurrentWeapon()->WeaponData->ClipSize);
}

void UWeaponController::Client_UpdateAmmo_Implementation(uint32 ServerAmmo)
{
	if(Character->HasAuthority())
	{
		return;
	}

	CurrentAmmo = ServerAmmo;
	AmmoSequence--;
	CurrentAmmo -= AmmoSequence;
}


void UWeaponController::Server_SetReload_Implementation(bool bIsReload)
{
	bIsReloading = bIsReload;

	if(Character && Character->WeaponManager->GetCurrentWeapon())
	{
		if(!bIsReload)
		{
			const uint32 AmmoNeeded = Character->WeaponManager->GetCurrentWeapon()->WeaponData->ClipSize - CurrentAmmo;
			CurrentAmmo = FMath::Clamp(CurrentAmmo + AmmoNeeded, 0, Character->WeaponManager->GetCurrentWeapon()->WeaponData->ClipSize);
			Client_AddAmmo(AmmoNeeded);
		}
	}
}

void UWeaponController::OnReloadEnd()
{
	const uint32 AmmoNeeded = Character->WeaponManager->GetCurrentWeapon()->WeaponData->ClipSize - CurrentAmmo;
	CurrentAmmo = FMath::Clamp(CurrentAmmo + AmmoNeeded, 0, Character->WeaponManager->GetCurrentWeapon()->WeaponData->ClipSize);

	bIsReloading = false;
	Server_SetReload(false);

	Character->WeaponManager->GetCurrentWeapon()->EndReloadLocal();
}



void UWeaponController::ReloadPressed()
{
	if(!Character || !Character->WeaponManager->GetCurrentWeapon())
	{
		return;
	}

	bIsReloading = true;
	Character->WeaponManager->GetCurrentWeapon()->ReloadLocal();

	const bool bEmpty = CurrentAmmo == 0;
	Server_SetReload(true);
	GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &UWeaponController::OnReloadEnd,
		Character->WeaponManager->GetCurrentWeapon()->GetReloadAnim(bEmpty)->GetPlayLength(), false);
}

void UWeaponController::InspectPressed()
{
	if(!Character || !Character->WeaponManager->GetCurrentWeapon() || bIsReloading)
	{
		return;
	}

	if(bIsAiming)
	{
		bIsAiming = false;
	}
	
	Character->WeaponManager->GetCurrentWeapon()->InspectLocal();
	bIsInspecting = true;
	Server_SetInspect(true);
	
	GetWorld()->GetTimerManager().SetTimer(InspectTimerHandle, this, &UWeaponController::OnInspectEnd,
	Character->WeaponManager->GetCurrentWeapon()->WeaponData->FirstPersonCharacterPoseInspect->GetPlayLength(), false);
}

void UWeaponController::Server_SetInspect_Implementation(bool bIsInspect)
{
	if(bIsAiming)
	{
		bIsAiming = false;
	}
	bIsInspecting = bIsInspect;
}


void UWeaponController::OnInspectEnd()
{
	bIsInspecting = false;
	Server_SetInspect(false);
}


void UWeaponController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UWeaponController, FireCount);
	DOREPLIFETIME(UWeaponController, bIsReloading);
	DOREPLIFETIME(UWeaponController, bIsAiming);
	DOREPLIFETIME(UWeaponController, bIsInspecting);
}

void UWeaponController::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AFPSGameCharacter>(GetOwner());
}

void UWeaponController::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bIsFiring && GetWorld()->GetRealTimeSeconds() - LastAttackTime > Character->WeaponManager->GetCurrentWeapon()->WeaponData->FireRate)
	{
		LastAttackTime = GetWorld()->GetRealTimeSeconds();
	}
	else
	{
		return;
	}

	Fire();
}


void UWeaponController::OnRep_IsAiming()
{
}

void UWeaponController::OnRep_IsInspecting()
{
	if(bIsInspecting)
	{
		if(Character->WeaponManager->GetCurrentWeapon()->ThirdPersonWeapon)
		{
			Character->WeaponManager->GetCurrentWeapon()->ThirdPersonWeapon->OnInspect();
		}
	}
}

void UWeaponController::OnRep_IsReloading()
{

	if(bIsReloading)
	{
		if(Character->WeaponManager->GetCurrentWeapon()->ThirdPersonWeapon)
		{
			Character->WeaponManager->GetCurrentWeapon()->ThirdPersonWeapon->OnReload(false);
		}
	}
}



