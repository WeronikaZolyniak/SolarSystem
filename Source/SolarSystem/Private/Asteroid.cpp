// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroid.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACelestialBody_CppBase::StaticClass(), CelestialBodies);
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform NewTransform;

	FVector OverallGravityPull = FVector(0,0,0);

	for (AActor* CelestialBody : CelestialBodies)
	{
		float DistanceToCelestialBody = FVector(CelestialBody->GetActorTransform().GetLocation() - GetActorTransform().GetLocation()).Length();
		int GravitationalPull = Cast<ACelestialBody_CppBase>(CelestialBody)->GravitationalPullRadius;
		if (DistanceToCelestialBody < GravitationalPull)
		{
			//UE_LOG(LogTemp, Warning, TEXT("close"));
			float CelestialBodyGravityValue = Cast<ACelestialBody_CppBase>(CelestialBody)->Gravity;
			FVector GravityPull = CelestialBody->GetActorTransform().GetLocation() - GetActorTransform().GetLocation();
			GravityPull.Normalize();
			OverallGravityPull += GravityPull;
		}
	}
	//UE_LOG(LogTemp, Error, TEXT("%f %f %f"), OverallGravityPull.X, OverallGravityPull.Y, OverallGravityPull.Z);
	NewTransform.SetLocation(GetActorTransform().GetLocation() + (Speed * DeltaTime * GetActorForwardVector()) + OverallGravityPull);
	SetActorTransform(NewTransform);

	
}

