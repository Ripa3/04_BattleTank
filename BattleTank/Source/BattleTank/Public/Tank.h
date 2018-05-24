// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	void AimAt(FVector HitLocation);

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 2.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 8000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* LocalBarrel = nullptr;  //TODO remove

	double LastFireTime = 0;
	
};
