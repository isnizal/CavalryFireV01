// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include"Engine/World.h"

void UTankBarrel::Elevation(float perSeconds)
{

	auto Time = GetWorld()->GetTimeSeconds();
	auto GetSpecificRelativeSpeed = FMath::Clamp<float>(perSeconds, -1, 1);
	auto GetRotationElevate = MaxPerSeconds * GetSpecificRelativeSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + GetRotationElevate;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinAngle, MaxAngle);
	SetRelativeRotation(FRotator(Elevation,0,0));

	UE_LOG(LogTemp, Warning, TEXT("%f, Elevation->Barrel: %f"), Time, perSeconds);
}
