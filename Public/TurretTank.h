// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TurretTank.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class CAVALRYFIREV01_API UTurretTank : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	//declare  maxpersecond rotate yaw
	UPROPERTY(EditAnywhere,Category = Turret)
		float YawPerSecond = 25;
	
public:
	void TurretRotate(float YawRotator);
	
};
