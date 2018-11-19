// Fill out your copyright notice in the Description page of Project Settings.

#include "AimTankComponents.h"
#include"Classes/Components/StaticMeshComponent.h"
#include"GameFramework/Actor.h"
#include"TankBarrel.h"
#include"Kismet/GameplayStatics.h"
#include"Engine/World.h"


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
	//get the toss velocity vector
	FVector TossVelocity;
	//get start location vector by using barrel socket name position
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectiles"));
	//get projectiles name to use suggesst projectile velocity
	bool Projectiles = UGameplayStatics::SuggestProjectileVelocity(this, TossVelocity, StartLocation, HitLocation, launchspeed, true, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (Projectiles)
	{
		//set the vector of toss velocity to zero
		auto AimDirection = TossVelocity.GetSafeNormal();
		//get time seconds
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f, Aim solution found"), Time);
		//use toss velocity zero 
		MoveTowardsBarrel(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f, Aim solution not found"));
	}
}
void UAimTankComponents::MoveTowardsBarrel(FVector HitDirection)
{
	//get barrel forward vector with rotation
	auto BarrelRotationNormal = Barrel->GetForwardVector().Rotation();
	//get the barrel hit rotation
	auto RotateBarrel = HitDirection.Rotation();
	//get the rotator hit direction to minus with the barrel rotation
	auto GetRotator = RotateBarrel - BarrelRotationNormal;
	//set the barrel rotator with pitch
	Barrel->Elevation(GetRotator.Pitch);
	//UE_LOG(LogTemp, Warning, TEXT("Hit is:%s"), *HitDirection.ToString());

}

void UAimTankComponents::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}


