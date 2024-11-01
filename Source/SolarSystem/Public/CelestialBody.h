#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CelestialBody.generated.h"

UCLASS()
class SOLARSYSTEM_API ACelestialBody_CppBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACelestialBody_CppBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	FMatrix CreateMatrixFromDegrees(float Degrees);

	float const DegreesToRadiansConstant = 0.0176;

	UPROPERTY(EditAnywhere);
	float DegreesEachTick = 1;

	float DegreesToRadians = 0;

	FVector DistanceFromSun = FVector(0,0,0);

	UPROPERTY(EditAnywhere)
	ACelestialBody_CppBase* Sun;

	UPROPERTY(EditAnywhere)
	bool SunIsStatic = true;

	FVector LastSunLocation;

	FVector InitialPosition;
};
