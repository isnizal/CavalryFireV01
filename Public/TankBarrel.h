// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */

UCLASS(meta = (BlueprintSpawnableComponent),Hidecategories = ("Collision"))
class CAVALRYFIREV01_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevation(float perSeconds);
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxPerSeconds = 20.0f;
	//Sensible defaults
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxAngle = 40.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinAngle = 0.0f;

};
