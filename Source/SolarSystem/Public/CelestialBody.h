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

};
