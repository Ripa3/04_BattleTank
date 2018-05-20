// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Math/UnrealMathUtility.h"

void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto NewElevation = FMath::Clamp<float>(RawNewElevation, MinDegrees, MaxDegrees);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}


