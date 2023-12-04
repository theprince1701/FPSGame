#include "ThirdPersonWeapon.h"

AThirdPersonWeapon::AThirdPersonWeapon()
{
	bReplicates = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));

	AttackForward = CreateDefaultSubobject<UArrowComponent>(TEXT("AttackForward"));
	AttackForward->SetupAttachment(WeaponMesh);
	
	MuzzleForward = CreateDefaultSubobject<UArrowComponent>(TEXT("MuzzleForward"));
	MuzzleForward->SetupAttachment(WeaponMesh);

	ShellForward = CreateDefaultSubobject<UArrowComponent>(TEXT("ShellForward"));
	ShellForward->SetupAttachment(WeaponMesh);

	bReplicates = true;
}

void AThirdPersonWeapon::Init(AFPSGameCharacter* Player)
{
	SetActorRelativeLocation(DefaultSpawnLocation);
	SetActorRelativeRotation(DefaultSpawnRotation);
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, true);
	AttachToComponent(Player->GetMesh(), AttachmentRules, FName(TEXT("WeaponSlot")));
	Character = Player;
	InitBP();

}

void AThirdPersonWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void AThirdPersonWeapon::OnRep_Owner()
{
	Super::OnRep_Owner();

	Character = Cast<AFPSGameCharacter>(GetOwner());
}

bool AThirdPersonWeapon::IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget,
                                          const FVector& SrcLocation) const
{
	return Character && !(Character->IsOwnedBy(ViewTarget) || Character->IsOwnedBy(RealViewer));
}
