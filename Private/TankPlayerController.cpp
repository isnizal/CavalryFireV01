// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATankPlayer * ATankPlayerController:: GetControlledTank()
{
	return Cast<ATankPlayer>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	auto PlayerTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("Possessing tank : %s"), *(PlayerTank->GetName()));
}
