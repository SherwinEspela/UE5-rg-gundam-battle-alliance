// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ThrusterVfxController.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RGGUNDAMBA_API UThrusterVfxController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UThrusterVfxController();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void PlayBackpackThrusters();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystem* FXBackpackThruster1;

};
