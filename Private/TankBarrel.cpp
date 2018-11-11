// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevation(float perSeconds)
{
	//auto TankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Elevation()-Barrel: %s") ,perSeconds);
}
