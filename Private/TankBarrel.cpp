// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include"Engine/World.h"

void UTankBarrel::Elevation(float GetSpecificRelativeSpeed)
{
	//get specific float of the angle
	GetSpecificRelativeSpeed = FMath::Clamp<float>(GetSpecificRelativeSpeed, -1, +1);
	//get rotation speed to multiply with specific float using max angle and time
	auto GetRotationSpeed = MaxPerSeconds * GetSpecificRelativeSpeed * GetWorld()->DeltaTimeSeconds;
	//get the new elevation by addition the original y with rotation speed
	auto RawNewElevation = RelativeRotation.Pitch + GetRotationSpeed;
	//find specific angle with the current elevation, min and max.
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinAngle, MaxAngle);
	//set the original location into the new rotator of elevation
	SetRelativeRotation(FRotator(Elevation,0,0));

}
