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
		int StartDegrees = rand() % 361;
		float StartDegreesToRadians = StartDegrees * DegreesToRadiansConstant;

		FMatrix StartPositionMatrix = CreateMatrixFromRadians(StartDegreesToRadians);

		DistanceFromSun = StartPositionMatrix.TransformVector(DistanceFromSun);

		FTransform NewTransform;
		NewTransform.SetLocation(DistanceFromSun);
		NewTransform.SetRotation(GetActorTransform().GetRotation());
		NewTransform.SetScale3D(GetActorTransform().GetScale3D());
		SetActorTransform(NewTransform);
	}
	DegreesToRadians = DegreesEachTick * DegreesToRadiansConstant;
}

void ACelestialBody_CppBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FMatrix RotationMatrix = CreateMatrixFromRadians(DegreesToRadians);

	FVector Displacement = RotationMatrix.TransformVector(DistanceFromSun) - DistanceFromSun;

	FTransform NewTransform;
	NewTransform.SetLocation(GetActorTransform().GetLocation() + Displacement);
	NewTransform.SetRotation(GetActorTransform().GetRotation());
	NewTransform.SetScale3D(GetActorTransform().GetScale3D());


	SetActorTransform(NewTransform);
	DistanceFromSun = GetActorTransform().GetLocation();
}

FMatrix ACelestialBody_CppBase::CreateMatrixFromRadians(float Radians)
{
	return FMatrix(FPlane(cos(Radians), -sin(Radians), 0, 0),
		FPlane(sin(Radians), cos(Radians), 0, 0),
		FPlane(0, 0, 0, 1),
		FPlane(0, 0, 0, 1));
}

