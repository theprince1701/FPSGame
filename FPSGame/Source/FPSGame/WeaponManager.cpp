
#include "WeaponManager.h"

UWeaponManager::UWeaponManager()
{
} 

void UWeaponManager::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AFPSGameCharacter>(GetOwner());

	for(int i = 0; i < WeaponReferences.Num(); i++)
	{
		AWeapon* Weapon = Cast<AWeapon>(GetWorld()->SpawnActor(WeaponReferences[i]));
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
		Weapon->AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("SOCKET_Weapon")));
		Weapon->InitWeapon(Character);
		CurrentWeapon = Weapon;
	}
}

