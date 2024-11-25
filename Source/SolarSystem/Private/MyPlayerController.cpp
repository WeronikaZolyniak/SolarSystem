// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Shoot Asteroid"), EInputEvent::IE_Pressed, this, &AMyPlayerController::StartTimer);
	InputComponent->BindAction(TEXT("Shoot Asteroid"), EInputEvent::IE_Released, this, &AMyPlayerController::SpawnAsteroid);
}

void AMyPlayerController::StartTimer()
{
	SecondsOnTimerStart = GetWorld()->GetRealTimeSeconds();
}

void AMyPlayerController::SpawnAsteroid()
{
	double SecondsOnTimerEnd = GetWorld()->GetRealTimeSeconds();

	double ChargingTime = SecondsOnTimerEnd - SecondsOnTimerStart;

	//UE_LOG(LogTemp, Warning, TEXT("%f"), ChargingTime);

	FActorSpawnParameters SpawnParameters;
	AAsteroid* Asteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidBPClass, GetPawn()->GetActorTransform(), SpawnParameters);
	Asteroid->Speed = ChargingTime * 100;
}


