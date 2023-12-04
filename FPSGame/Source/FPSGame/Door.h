#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class FPSGAME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:
	ADoor();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;


private:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* ProximityTrigger;
	
	
	UFUNCTION()
	void OnPlayerEnterProximity(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlayerLeaveProximity(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool bIsDoorOpen;
};