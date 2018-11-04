// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATankPlayer * ATankPlayerController:: GetControlledTank()
{
	return Cast<ATankPlayer>(GetPawn());
}
void ATankPlayerController::AimTowardCrossHair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player hit: %s"),*(HitLocation.ToString()));
	}
	//find tank location trace with crosshair
	//if hit the landscape
		//tell the possess tank to aim at this crosshair
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardCrossHair();

}
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	HitLocation = FVector(1.0f);
	//use viewport to find crosshair
	//matches with the hit location
	return true;
}

void ATankPlayerController::BeginPlay()
{
	auto PlayerTank = GetControlledTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessing tank : %s"), *(PlayerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not possessing tank"));
	}
	
}
