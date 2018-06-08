// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/*
Tank Track is used to set maximum driving force and to apply forces to the tank
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UTankTrack();
	
	TArray<ASprungWheel*> GetWheels() const;

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	void DriveTrack(float CurrentThrottle);

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 50000000.f;
	
};
