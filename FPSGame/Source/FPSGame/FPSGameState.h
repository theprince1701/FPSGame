#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "FPSGamePlayerController.h"
#include "NiagaraSystem.h"
#include "Projectile.h"
#include "GameFramework/GameState.h"
#include "FPSGameState.generated.h"

USTRUCT(BlueprintType)
struct FImpact
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	int SurfaceType;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* Decal;
	UPROPERTY(EditDefaultsOnly)
	UNiagaraSystem* Vfx;
	UPROPERTY(EditDefaultsOnly)
	USoundBase* ImpactSFX;
};

USTRUCT(BlueprintType)
struct FTDMTeam
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	uint8 TeamID;
	
	UPROPERTY(BlueprintReadOnly)
	int32 Score;
	
	UPROPERTY(BlueprintReadOnly)
	TArray<AFPSPlayerState*> PlayerStates;

	FTDMTeam(uint8 TeamID)
		: TeamID(TeamID), Score(0)
	{
	}

	FTDMTeam() = default;
};


UCLASS()
class FPSGAME_API AFPSGameState : public AGameState
{
	GENERATED_BODY()

	//impacts
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<FImpact> Impacts;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USoundAttenuation* ImpactSoundAttenuation;
	
	UPROPERTY(EditDefaultsOnly)
	float MatchLength = 180.f;
	
public:
	void OnHit(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage, const FHitResult& Hit, bool bClientSim);
	void OnPlayerDeath(const AFPSGamePlayerController* Killer, AFPSGamePlayerController* Victim);
	void StartMatch();
	void RegisterPlayerForTeam(AFPSPlayerState* PlayerState, int32 TeamID);

	UPROPERTY(Replicated, BlueprintReadOnly)
	float MatchTimer;
	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 CurrentRound;
	UPROPERTY(Replicated, BlueprintReadOnly)
	float StartingGameTimer;
	UPROPERTY(Replicated)
	bool bCanInteract;

	UPROPERTY(BlueprintReadOnly, Replicated)
	FTDMTeam RedTeam;
	UPROPERTY(BlueprintReadOnly, Replicated)
	FTDMTeam BlueTeam;

protected:
	virtual void BeginPlay() override;
	virtual void OnRep_MatchState() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnHit(AFPSGameCharacter* DamageInstigator, int HitID, FVector Location, FRotator Rotation);

private:
	FTimerHandle FMatchStartingUpdateTimerHandle;
	FTimerHandle FUpdateMatchTimerHandle;

	void UpdateMatchStartingTimer();
	void UpdateMatchTimer();
	void ProcessDamage(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage);
	void SpawnEffect(AFPSGameCharacter* DamageInstigator, int HitID, FVector Location, FRotator Rotation);

	FORCEINLINE FImpact GetImpact(int SurfaceType)
	{
		for(int i = 0; i < Impacts.Num(); i++)
		{
			if(SurfaceType == Impacts[i].SurfaceType)
			{
				return Impacts[i];
			}
		}

		return Impacts[0];
	}

	FORCEINLINE int GetImpactIndex(int SurfaceType)
	{
		for(int i = 0; i < Impacts.Num(); i++)
		{
			if(SurfaceType == Impacts[i].SurfaceType)
			{
				return i;
			}
		}

		return 0;
	}

public:
};



