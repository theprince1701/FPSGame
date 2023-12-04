#pragma once

#include "CoreMinimal.h"
#include "FPSGameCharacter.h"
#include "GameFramework/SpectatorPawn.h"
#include "Spectator.generated.h"


UCLASS()
class FPSGAME_API ASpectator : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	virtual void Destroyed() override;

	virtual void Init(AFPSGameCharacter* Killer, FVector const& InLocation, FRotator const& InRotation);

private:
	UPROPERTY()
	AFPSGameCharacter* Target;
};
