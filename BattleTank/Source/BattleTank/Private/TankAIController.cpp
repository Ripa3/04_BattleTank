// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UTankAimingComponent* ControlledTankAimingComp = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO find useful radius

		ControlledTankAimingComp->AimAt(PlayerTank->GetActorLocation());
		ControlledTankAimingComp->Fire();  //TODO fix rate of fire
	}
}


