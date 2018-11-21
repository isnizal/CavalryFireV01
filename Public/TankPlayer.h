// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include"AimTankComponents.h"
#include "TankPlayer.generated.h"

class UTankBarrel;
class UTurretTank;
UCLASS()
class CAVALRYFIREV01_API ATankPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UAimTankComponents * AimingTankComponents = nullptr;
	UFUNCTION(BlueprintCallable, Category = Method)
	virtual void TankFire() const;
public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel * BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTurretTank * TurretToSet);
	UPROPERTY(EditAnywhere, Category = CanonFire)
	float launchSpeed = 10000;
	
};
