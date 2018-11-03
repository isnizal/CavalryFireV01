// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include"Engine/World.h"

void ATankAIController::BeginPlay()
{
	auto AIController = PlayerTank();
	if (AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessing tank : %s"), *(AIController->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not possessing AI controller"));
	}
}
ATankPlayer * ATankAIController::GetControlledTank()
{
	return Cast<ATankPlayer>(GetPawn());
}

ATankPlayer * ATankAIController::PlayerTank()
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATankPlayer>(PlayerTank);
}