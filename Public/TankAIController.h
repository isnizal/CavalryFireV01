// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include"TankPlayer.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class CAVALRYFIREV01_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATankPlayer * GetControlledTank();
	ATankPlayer * PlayerTank();
protected:
	virtual void BeginPlay() override;

	
	
};
