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
		InitialPosition = GetActorTransform().GetLocation();

		LastSunLocation = Sun->GetActorTransform().GetLocation();

		FVector DisplacementAfterRotation = LastSunLocation - Sun->InitialPosition;
		SetActorTransform(FTransform(GetActorTransform().GetRotation(), GetActorTransform().GetLocation() + DisplacementAfterRotation, GetActorTransform().GetScale3D()));
		
		DistanceFromSun = GetActorTransform().GetLocation() - Sun->GetActorTransform().GetLocation();
		int StartDegrees = rand() % 361;

		FMatrix StartPositionMatrix = CreateMatrixFromDegrees(StartDegrees);

		DistanceFromSun = StartPositionMatrix.TransformVector(DistanceFromSun);

		FTransform NewTransform;
		NewTransform.SetLocation(DistanceFromSun + Sun->GetActorTransform().GetLocation());
		SetActorTransform(NewTransform);

	}
}

void ACelestialBody_CppBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Sun)
	{
		FVector Difference = Sun->GetActorTransform().GetLocation() - LastSunLocation;
		SetActorTransform(FTransform(GetActorTransform().GetRotation(), GetActorTransform().GetLocation() + Difference, GetActorTransform().GetScale3D()));
		LastSunLocation = Sun->GetActorTransform().GetLocation();
		DistanceFromSun = GetActorTransform().GetLocation() - Sun->GetActorTransform().GetLocation();

		FMatrix RotationMatrix = CreateMatrixFromDegrees(DegreesEachTick);

		FVector Displacement = RotationMatrix.TransformVector(DistanceFromSun) - DistanceFromSun;

		FTransform NewTransform;
		NewTransform.SetLocation(GetActorTransform().GetLocation() + Displacement);

		SetActorTransform(NewTransform);
		DistanceFromSun = GetActorTransform().GetLocation();
	}
}

FMatrix ACelestialBody_CppBase::CreateMatrixFromDegrees(float Degrees)
{
	FMatrix Matrix = FRotationMatrix::Make(FQuat::MakeFromEuler(FVector(0, 0, Degrees)));
	return Matrix;
}

