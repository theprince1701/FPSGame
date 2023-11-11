

#include "WeaponController.h"

#include "FPSGameCharacter.h"
#include "WeaponManager.h"
#include "Net/UnrealNetwork.h"

UWeaponController::UWeaponController()
{
	SetIsReplicated(true);
}

void UWeaponController::FirePressed()
{
	if(!Character->WeaponManager->GetCurrentWeapon())
	{
		return;
	}
	
	bIsFiring = true;

	Fire();
	GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &UWeaponController::Fire,
		Character->WeaponManager->GetCurrentWeapon()->FireRate, true);
}

void UWeaponController::FireReleased()
{
	bIsFiring = false;

	GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
}


void UWeaponController::Fire()
{
	if(!bIsFiring)
	{
		GetWorld()->GetTimerManager().ClearTimer(FireTimerHandle);
		return;
	}

	Character->WeaponManager->GetCurrentWeapon()->FireLocal();
	Server_Fire();
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



void UWeaponController::ReloadPressed()
{
}

void UWeaponController::InspectPressed()
{
}

void UWeaponController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UWeaponController, FireCount);
	
}

void UWeaponController::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AFPSGameCharacter>(GetOwner());

}


void UWeaponController::OnRep_FireCount()
{
}

void UWeaponController::OnRep_IsAiming()
{
}

void UWeaponController::Server_Fire_Implementation()
{
}


