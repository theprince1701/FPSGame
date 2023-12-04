#include "Projectile.h"

#include "FPSGameState.h"
#include "GameHUD.h"
#include "WeaponData.h"

AProjectile::AProjectile()
{
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);	

	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	RootComponent = CollisionComp;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	InitialLifeSpan = 3.0f;
}

void AProjectile::Init(UWeaponData* WD)
{
	WeaponData = WD;
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                        FVector NormalImpulse, const FHitResult& Hit)
{
	if(AFPSGameCharacter* InstigatorPtr = Cast<AFPSGameCharacter>(GetInstigator()))
	{
		if(AFPSGamePlayerController* PC = Cast<AFPSGamePlayerController>(InstigatorPtr->GetController()))
		{
			PC->OnHit(InstigatorPtr, Cast<AFPSGameCharacter>(OtherActor), WeaponData->Damage, Hit);
		}
	}

	if(OtherActor->CanBeDamaged())
	{
		if(APlayerController* PC = Cast<APlayerController>(GetOwner()->GetInstigatorController()))
		{
			if(AGameHUD* GameHUD = Cast<AGameHUD>(PC->GetHUD()))
			{
				UE_LOG(LogTemp, Warning, TEXT("OnHitDamagedTarget"));
				GameHUD->CrossHairWidget->OnHitDamagedTarget();
			}
		}
	}
	Destroy();
}
