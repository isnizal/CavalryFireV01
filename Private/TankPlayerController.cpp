// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankPlayer.h"
#include"Classes/Engine/World.h"


ATankPlayer * ATankPlayerController:: GetControlledTank()const
{
	return Cast<ATankPlayer>(GetPawn());
}
void ATankPlayerController::AimTowardCrossHair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	//find tank location trace with crosshair
	//tell the possess tank to aim at this crosshair
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player hit: %s"),*(HitLocation.ToString()));
	}

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
	//get the viewport size 
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	//use viewport as fvector 2d to find the position of crosshair x and y
	auto ScreenLocation = FVector2D(CrossHairX * ViewPortSizeX, CrossHairY* ViewPortSizeY);
	//convert the screen position into the world
	FVector WorldDirection;
	if (LookDirection(ScreenLocation,WorldDirection))
	{
		//how long the trace hitting the landscape
		if (GetVictorHitLocation(WorldDirection, HitLocation))
		{
			GetControlledTank()->AimAt(HitLocation);
		}
		return true;
	}
	return true;
}
bool ATankPlayerController::GetVictorHitLocation(FVector WorldDirection, FVector& HitLocation) const
{
	//hit result of line trace
	FHitResult HitResult;
	//find the start location of the camera
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	//end location  should be the start location multiply with the line trace
	FVector EndLocation = StartLocation + (WorldDirection * LineTraceRange);
	//spawn line trace using the with the hit result, start, and end location
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		//show of hit result with the location
		HitLocation = HitResult.Location;
		return true;
	}
	//if false show vector 0.
	 HitLocation = FVector(0.0f);
	 return false;
}
bool ATankPlayerController::LookDirection(FVector2D ScreenLocation, FVector & WorldDirection) const
{
	//find the world space
	FVector WorldSpace;
	//return 2d screen using screen location of x and y with world direction
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
