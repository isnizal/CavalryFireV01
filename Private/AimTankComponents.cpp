// Fill out your copyright notice in the Description page of Project Settings.

#include "AimTankComponents.h"
#include"Classes/Components/StaticMeshComponent.h"
#include"GameFramework/Actor.h"


// Sets default values for this component's properties
UAimTankComponents::UAimTankComponents()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimTankComponents::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimTankComponents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimTankComponents::AimAt(FVector HitLocation, float launchspeed)
{
	FVector TossVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectiles"));
	auto AimDirection = TossVelocity.GetSafeNormal();
	UE_LOG(LogTemp, Warning, TEXT("Firing at: %s"), *AimDirection.ToString());
}

void UAimTankComponents::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}


