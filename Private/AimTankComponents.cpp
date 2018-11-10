// Fill out your copyright notice in the Description page of Project Settings.

#include "AimTankComponents.h"
#include"Classes/Components/StaticMeshComponent.h"
#include"GameFramework/Actor.h"
#include"Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UAimTankComponents::UAimTankComponents()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UAimTankComponents::AimAt(FVector HitLocation, float launchspeed)
{
	FVector TossVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectiles"));
	bool Projectiles = UGameplayStatics::SuggestProjectileVelocity(this, TossVelocity, StartLocation, HitLocation, launchspeed, true, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (Projectiles)
	{
		auto AimDirection = TossVelocity.GetSafeNormal();

		
		MoveTowardsBarrel(AimDirection);
	}
}
void UAimTankComponents::MoveTowardsBarrel(FVector HitDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto RotateBarrel = HitDirection.Rotation();
	auto GetRotator = RotateBarrel - BarrelRotation;
	auto TankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Rotate at: %s"), *TankName, *GetRotator.ToString());

}

void UAimTankComponents::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}


