// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "WeaponData.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameGameMode.generated.h"

namespace MatchState
{
	extern FPSGAME_API const FName StartingRound;
	extern FPSGAME_API const FName EndingRound;
}



USTRUCT(BlueprintType)
struct FRoundWeapons
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	int Round;
	UPROPERTY(EditDefaultsOnly)
	UWeaponData* WeaponData;

	FRoundWeapons()
		: Round(0), WeaponData(nullptr)
	{
	}
};
UCLASS(minimalapi)
class AFPSGameGameMode : public AGameMode
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFPSGameCharacter> Player;
	UPROPERTY(EditDefaultsOnly)
	int32 TeamSize = 1;
	UPROPERTY(EditDefaultsOnly)
	int32 NumRounds = 3;
	UPROPERTY(EditDefaultsOnly)
	float RoundBeginDelay = 10.f;
	UPROPERTY(EditDefaultsOnly)
	float RoundEndDelay = 5.f;
	UPROPERTY(EditDefaultsOnly)
	TArray<FRoundWeapons> RoundWeapons;
	UPROPERTY(EditDefaultsOnly)
	bool bStartWithOnePlayer;
	
public:
	AFPSGameGameMode();
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
	UFUNCTION()
	virtual void SpawnPlayer(APlayerController* NewPlayer, int32 TeamID);

	void OnPlayerJoinedTeam(int32 TeamID, APlayerController* PC);

	virtual void EndRound(int32 Winner);
protected:
	virtual bool ReadyToStartMatch_Implementation() override;
	virtual void RespawnAllPlayers();

private:
	FTimerHandle BeginNextRoundTimerHandle;
	FRoundWeapons GetRoundWeapon();

	UFUNCTION()
	void BeginNextRound();
	
	virtual bool BothTeamsFull();
};



