// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RGGABaseAnimInstance.generated.h"

class ARGGBaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class RGGUNDAMBA_API URGGABaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float MovementSpeed;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float MovementOffsetYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	FRotator MovementRotation;

private:
	TObjectPtr<ARGGBaseCharacter> BaseCharacter;
	TObjectPtr<UCharacterMovementComponent> MovementComponent;
	
};
