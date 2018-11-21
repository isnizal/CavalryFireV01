// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayer.h"


// Sets default values
ATankPlayer::ATankPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AimingTankComponents = CreateDefaultSubobject<UAimTankComponents>(FName("AimTankComponents"));

}

// Called when the game starts or when spawned
void ATankPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankPlayer::TankFire() const
{
	UE_LOG(LogTemp, Log, TEXT("Tank is firing"));
}


// Called to bind functionality to input
void ATankPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATankPlayer::AimAt(FVector HitLocation)
{
	AimingTankComponents->AimAt(HitLocation, launchSpeed);
}

void ATankPlayer::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	AimingTankComponents->SetBarrelReference(BarrelToSet);
}

void ATankPlayer::SetTurretReference(UTurretTank * TurretToSet)
{
	AimingTankComponents->SetTurretReference(TurretToSet);
}

