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
	ATankPlayer * GetControlledTank() const;
	
	
protected:
	void AimTowardCrossHair();
	void Tick(float DeltaSeconds);
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	bool GetVictorHitLocation(FVector WorldDirection, FVector  &HitLocation) const;
	bool LookDirection(FVector2D ScreenLocation, FVector & WorldDirection) const;
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category = CrossHair)
		float CrossHairX = 0.5;
	UPROPERTY(EditAnywhere, Category = CrossHair)
		float CrossHairY = 0.33;
	UPROPERTY(EditAnywhere, Category = LineTrace)
	float LineTraceRange = 1000000.0f;
};
