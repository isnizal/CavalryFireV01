// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretTank.h"

void UTurretTank::TurretRotate(float YawRotator)
{
	//get the specific float for the rotate tank
	FMath::Clamp<float>(YawRotator, -1, 1);
	//get the yaw persecond 
	auto RotateYaw = YawPerSecond * GetWorld()->DeltaTimeSeconds * YawRotator;
	//get the rotate angle
	auto GetRotateAngle = RelativeRotation.Yaw + RotateYaw;
	//set the rotate angle to the new position
	SetRelativeRotation(FRotator(0,GetRotateAngle,0));
}
