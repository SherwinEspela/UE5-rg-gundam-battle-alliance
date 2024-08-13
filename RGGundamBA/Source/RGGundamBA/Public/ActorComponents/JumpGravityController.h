// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JumpGravityController.generated.h"

class UCurveFloat;
class UCharacterMovementComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RGGUNDAMBA_API UJumpGravityController : public UActorComponent
{
	GENERATED_BODY()

public:	
	UJumpGravityController();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void HandleJumpStarted();
	void HandleJumpApexReached();
	void Reset();

	bool bCanAdjustGravity;
	bool bJumpStarted;
	bool bJumpApexReached;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Gravity Value Curve")
	UCurveFloat* CurveGravityAfterApex;

	UPROPERTY(EditAnywhere, Category = "Gravity Scale")
	float GravityScaleReset = 4.f;

	UPROPERTY(EditAnywhere, Category = "Gravity Scale")
	float GravityScaleDecreaseRate = 0.01f;

	UPROPERTY(EditAnywhere, Category = "Gravity Scale")
	float GravityScaleIncreaseRate = 0.5f;

private:
	UCharacterMovementComponent* CharacterMovement;

};
