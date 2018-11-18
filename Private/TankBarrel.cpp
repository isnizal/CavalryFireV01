// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include"Engine/World.h"

void UTankBarrel::Elevation(float perSeconds)
{
	//auto TankName = GetOwner()->GetName();
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f:Elevation()-Barrel: %f") ,Time, perSeconds );
}
