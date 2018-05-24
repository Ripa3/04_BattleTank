// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (bIsReloaded)
	{
		if (!ensure(LocalBarrel)) { return; }
		//spawn a projectile at socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			LocalBarrel->GetSocketLocation(FName("Projectile")),
			LocalBarrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


