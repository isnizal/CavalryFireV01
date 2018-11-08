// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include"Classes/Engine/World.h"


ATankPlayer * ATankPlayerController:: GetControlledTank()const
{
	return Cast<ATankPlayer>(GetPawn());
}
void ATankPlayerController::AimTowardCrossHair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player hit: %s"),*(HitLocation.ToString()));
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
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//use viewport to find crosshair
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(CrossHairX * ViewPortSizeX, CrossHairY* ViewPortSizeY);
	//UE_LOG(LogTemp, Warning, TEXT("Screen size is : %s"), *(ScreenLocation.ToString()))
	//convert the screen position into the world
	FVector WorldDirection;
	if (LookDirection(ScreenLocation,WorldDirection))
	{
		//how long the trace hitting the landscape
		if (GetVictorHitLocation(WorldDirection, HitLocation))
		{
			GetControlledTank()->AimAt(HitLocation);
		}
		
	}
	
	return true;
}
bool ATankPlayerController::GetVictorHitLocation(FVector WorldDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (WorldDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	 HitLocation = FVector(0.0f);
	 return false;
}
bool ATankPlayerController::LookDirection(FVector2D ScreenLocation, FVector & WorldDirection) const
{
	FVector WorldSpace;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldSpace, WorldDirection);
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
