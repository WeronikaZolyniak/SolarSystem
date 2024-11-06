// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroid.h"
#include "DrawDebugHelpers.h"

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
	
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FTransform NewTransform;

	NewTransform.SetLocation(GetActorTransform().GetLocation() + (Speed * DeltaTime * GetActorForwardVector()));
	SetActorTransform(NewTransform);
}

