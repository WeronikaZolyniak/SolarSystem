#include "CelestialBody.h"

ACelestialBody_CppBase::ACelestialBody_CppBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACelestialBody_CppBase::BeginPlay()
{
	Super::BeginPlay();
	if (Sun)
	{
		DistanceFromSun = GetActorTransform().GetLocation() - Sun->GetActorTransform().GetLocation();
	}
	DegreesToRadians = DegreesEachTick * 0.0176;
}

void ACelestialBody_CppBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FMatrix RotationMatrix(FPlane(cos(DegreesToRadians), -sin(DegreesToRadians), 0, 0),
		FPlane(sin(DegreesToRadians), cos(DegreesToRadians), 0, 0),
		FPlane(0, 0, 0, 1),
		FPlane(0, 0, 0, 1));

	FVector Displacement = RotationMatrix.TransformVector(DistanceFromSun) - DistanceFromSun;

	FTransform NewTransform;
	NewTransform.SetLocation(GetActorTransform().GetLocation() + Displacement);
	NewTransform.SetRotation(GetActorTransform().GetRotation());
	NewTransform.SetScale3D(GetActorTransform().GetScale3D());


	SetActorTransform(NewTransform);
	DistanceFromSun = GetActorTransform().GetLocation();
}

