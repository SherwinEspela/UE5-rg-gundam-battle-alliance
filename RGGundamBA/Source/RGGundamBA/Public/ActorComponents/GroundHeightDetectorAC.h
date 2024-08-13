// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GroundHeightDetectorAC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RGGUNDAMBA_API UGroundHeightDetectorAC : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGroundHeightDetectorAC();

	void MeasureGroundDistance();
	void CheckDistanceToGroundByLineTrace();

public:
	UPROPERTY(BlueprintReadonly, Category = "Distance to Ground")
	float DistanceToGround = 1000.f;

	UPROPERTY(BlueprintReadonly, Category = "Distance to Ground")
	bool bCanMeasure = false;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
