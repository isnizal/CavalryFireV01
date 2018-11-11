// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AimTankComponents.generated.h"

class UTankBarrel;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAVALRYFIREV01_API UAimTankComponents : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimTankComponents();
	void AimAt(FVector HitLocation, float launchspeed);
	void MoveTowardsBarrel(FVector HitDirection);
	void SetBarrelReference(UTankBarrel * BarrelToSet);

protected:
	// Called when the game start

public:	
	// Called every frame

private:	
	UTankBarrel * Barrel = nullptr;

		
	
};
