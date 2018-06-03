// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!ensure(GetPawn())) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
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

		//checks the aiming firing state
		auto ComponentFiringState = ControlledTankAimingComp->GetFiringState();
		if (ComponentFiringState == EFiringStatus::Locked)
		{
			ControlledTankAimingComp->Fire();
		}
		//TODO fix rate of fire
	}
}



