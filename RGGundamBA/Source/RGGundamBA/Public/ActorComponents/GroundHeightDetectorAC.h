// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GroundHeightDetectorAC.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDistanceToGroundReached);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RGGUNDAMBA_API UGroundHeightDetectorAC : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGroundHeightDetectorAC();

	void MeasureGroundDistance();

	UFUNCTION(BlueprintCallable)
	void Reset();

public:
	UPROPERTY(BlueprintReadonly, Category = "Distance to Ground")
	float DistanceToGround = 1000.f;

	UPROPERTY(BlueprintReadonly, Category = "Distance to Ground")
	bool bCanMeasure = false;

	FDistanceToGroundReached OnDistanceToGroundReached;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void CheckDistanceToGroundByLineTrace();

};
