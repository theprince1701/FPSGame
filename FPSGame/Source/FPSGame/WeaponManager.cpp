
#include "WeaponManager.h"

#include "WeaponData.h"
#include "Net/UnrealNetwork.h"

UWeaponManager::UWeaponManager()
{
} 

void UWeaponManager::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AFPSGameCharacter>(GetOwner());
	//InitWeapons();
}

void UWeaponManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UWeaponManager, CurrentWeapon);
	DOREPLIFETIME(	UWeaponManager, Weapons);
}

void UWeaponManager::OnRep_CurrentWeapon()
{
	Character = Cast<AFPSGameCharacter>(GetOwner());

	if(CurrentWeapon && Character->IsLocallyControlled())
	{
		CurrentWeapon->Show();
		Character->WeaponController->CurrentAmmo = CurrentWeapon->WeaponData->ClipSize;

	}
}

void UWeaponManager::OnRep_Weapons()
{
	if(Character && Character->IsLocallyControlled())
	{
		UE_LOG(LogTemp, Warning, TEXT("OnRep_Weapons"));
		SetCurrentWeapon(0);
	}
}

void UWeaponManager::InitWeapons()
{
	if(!Character->HasAuthority())
	{
		return;
	}

	for(int i = 0; i < WeaponReferences.Num(); i++)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

		AThirdPersonWeapon* ThirdPersonWeapon = Cast<AThirdPersonWeapon>(GetWorld()->SpawnActor(WeaponReferences[i]->TPWeapon));
		ThirdPersonWeapon->Init(Character);
		ThirdPersonWeapon->SetOwner(GetOwner());

		AWeapon* FirstPersonWeapon = Cast<AWeapon>(GetWorld()->SpawnActor(WeaponReferences[i]->FPWeapon));
		
		FirstPersonWeapon->AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("SOCKET_Weapon")));
		FirstPersonWeapon->SetOwner(Character);
		FirstPersonWeapon->ThirdPersonWeapon = ThirdPersonWeapon;
		FirstPersonWeapon->Character = Character;
		FirstPersonWeapon->Init();

//		FirstPersonWeapon->SetActorHiddenInGame(true);
		CurrentWeapon = FirstPersonWeapon;

	}
	
	if(CurrentWeapon)	
	{
		CurrentWeapon->Show();
		UE_LOG(LogTemp, Warning, TEXT("CurrentWeapon"));
	}
//	OnRep_Weapons();

}

void UWeaponManager::IncrementCurrentWeapon()
{
	CurrentWeaponIndex++;
	SetCurrentWeapon(CurrentWeaponIndex);
}

void UWeaponManager::DecrementCurrentWeapon()
{
	CurrentWeaponIndex--;
	SetCurrentWeapon(CurrentWeaponIndex);
}

void UWeaponManager::SetWeapon(UWeaponData* WeaponData)
{
	if(!Character)
	{
		Character = Cast<AFPSGameCharacter>(GetOwner());
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	AThirdPersonWeapon* ThirdPersonWeapon = Cast<AThirdPersonWeapon>(GetWorld()->SpawnActor(WeaponData->TPWeapon));
	ThirdPersonWeapon->Init(Character);
	ThirdPersonWeapon->SetOwner(GetOwner());

	AWeapon* FirstPersonWeapon = Cast<AWeapon>(GetWorld()->SpawnActor(WeaponData->FPWeapon));
		
	FirstPersonWeapon->AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("SOCKET_Weapon")));
	FirstPersonWeapon->SetOwner(Character);
	FirstPersonWeapon->ThirdPersonWeapon = ThirdPersonWeapon;
	FirstPersonWeapon->Character = Character;
	FirstPersonWeapon->Init();

	CurrentWeapon = FirstPersonWeapon;
	Character->WeaponController->CurrentAmmo = CurrentWeapon->WeaponData->ClipSize;
	UE_LOG(LogTemp, Warning, TEXT("CurrentWeapon"));
	OnRep_CurrentWeapon();
}

void UWeaponManager::SetCurrentWeapon(int WeaponIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("%i")	, Weapons.Num());

	if(CurrentWeapon)
	{
		if(WeaponIndex >= Weapons.Num())
		{
			WeaponIndex = 0;
		}
		else if(WeaponIndex < 0)
		{
			WeaponIndex = Weapons.Num() - 1;
		}

		SwapWeapons(WeaponIndex);
		return;
	}


	AWeapon* NextWeapon = Weapons[WeaponIndex];
	CurrentWeapon = NextWeapon;
	Server_SetCurrentWeapon(NextWeapon);

	if(CurrentWeapon)
	{
		NextWeapon->SetActorHiddenInGame(false);
		CurrentWeaponIndex = WeaponIndex;
		NextWeapon->Show();
	}
}

void UWeaponManager::SwapWeapons(int NewIndex)
{
	AWeapon* NextWeapon = Weapons[NewIndex];

	bSwitching = true;
	CurrentWeapon->Hide();

	FTimerDelegate HideCurrentWeapon = FTimerDelegate::CreateUObject(this, &UWeaponManager::OnCurrentWeaponHidden, NextWeapon);
	GetWorld()->GetTimerManager().SetTimer(HideCurrentWeaponTimerHandle, HideCurrentWeapon,
		CurrentWeapon->WeaponData->FirstPersonCharacterPoseHolster->GetPlayLength(), false);
}

void UWeaponManager::Server_SetCurrentWeapon_Implementation(AWeapon* NewWeapon)
{
	CurrentWeapon = NewWeapon;
}

void UWeaponManager::OnCurrentWeaponHidden(AWeapon* NewWeapon)
{
	FTimerDelegate ShowNewWeapon = FTimerDelegate::CreateUObject(this, &UWeaponManager::OnNewWeaponShowed, NewWeapon);
	GetWorld()->GetTimerManager().SetTimer(ShowNewWeaponTimerHandle, ShowNewWeapon,
		NewWeapon->WeaponData->FirstPersonCharacterPoseUnHolster->GetPlayLength(), false);

	CurrentWeapon->SetActorHiddenInGame(true);
	CurrentWeapon = NewWeapon;
	Server_SetCurrentWeapon(NewWeapon);
	CurrentWeapon->Show();
	NewWeapon->SetActorHiddenInGame(false);
	CurrentWeaponIndex = Weapons.Find(NewWeapon);
}

void UWeaponManager::OnNewWeaponShowed(AWeapon* NewWeapon)
{
	bSwitching = false;
}

