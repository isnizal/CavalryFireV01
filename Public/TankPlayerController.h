// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include"TankPlayer.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CAVALRYFIREV01_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayer * GetControlledTank();
	
protected:
	virtual void BeginPlay() override;
	
	
};
