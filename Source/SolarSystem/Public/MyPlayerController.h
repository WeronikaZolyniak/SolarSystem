// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Asteroid.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEM_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void SetupInputComponent() override;

	void StartTimer();
	void SpawnAsteroid();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AAsteroid> AsteroidBPClass;

	double SecondsOnTimerStart;
	
};
