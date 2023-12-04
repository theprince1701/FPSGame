// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthComponent.h"

#include "FPSGameCharacter.h"
#include "FPSGameState.h"
#include "WeaponManager.h"
#include "Components/CapsuleComponent.h"
#include "Net/UnrealNetwork.h"

UPlayerHealthComponent::UPlayerHealthComponent()
{
//	SetIsReplicated(true);
}

void UPlayerHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = 100.f;
	Character = Cast<AFPSGameCharacter>(GetOwner());

	if(Character->HasAuthority())
	{
		GetWorld()->GetTimerManager().SetTimer(RegenUpdateTimerHandle,
			this, &UPlayerHealthComponent::RegenHealthUpdate, .2f, true);
	}
}

void UPlayerHealthComponent::OnDeath()
{
	bIsDead = true;
	CurrentHealth = 0;
	Character->WeaponManager->CurrentWeapon->ThirdPersonWeapon->Destroy();
	Character->WeaponManager->CurrentWeapon->Destroy();
	OnRep_IsDead();
}

void UPlayerHealthComponent::OnRep_IsDead()
{
	if(Character)
	{
		Character->OnDeath();
	}
}

void UPlayerHealthComponent::OnRep_CurrentHealth()
{
	if(Character && Character->IsLocallyControlled())
	{
		
	}
}

void UPlayerHealthComponent::RegenHealthUpdate()
{
	if(GetWorld()->GetTimeSeconds() - LastDamageTime > 5.f && CurrentHealth < 100.f)
	{
		CurrentHealth += 5.f;

		if(CurrentHealth > 100.f)
		{
			CurrentHealth = 100.f;
		}

		if(CurrentHealth < 0.f)
		{
			CurrentHealth = 0.f;
		}
		OnRep_CurrentHealth();
	}
}


void UPlayerHealthComponent::ApplyDamage(AController* Instigator, float Damage)
{
	if(bIsDead)
	{
		return;
	}

	LastDamageTime = GetWorld()->GetTimeSeconds();
	
	CurrentHealth -= Damage;
	OnRep_CurrentHealth();

	if(CurrentHealth <= 0)
	{
		OnDeath();
		CurrentHealth = 0.0f;
		if(AFPSGameState* GameState = GetWorld()->GetGameState<AFPSGameState>())
		{
			if(AFPSGamePlayerController* Killer = Cast<AFPSGamePlayerController>(Instigator))
			{
				GameState->OnPlayerDeath(Killer, Cast<AFPSGamePlayerController>(Character->Controller));
			}
		}
	}
}

void UPlayerHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UPlayerHealthComponent, CurrentHealth);
	DOREPLIFETIME(UPlayerHealthComponent, bIsDead);
}

