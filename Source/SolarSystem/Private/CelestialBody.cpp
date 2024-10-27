#include "CelestialBody.h"

ACelestialBody_CppBase::ACelestialBody_CppBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACelestialBody_CppBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACelestialBody_CppBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

