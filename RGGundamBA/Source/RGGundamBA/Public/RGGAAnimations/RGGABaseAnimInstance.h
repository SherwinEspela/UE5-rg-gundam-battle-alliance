// Copyright 2024 Sherwin Espela. All rights reserved.

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

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	TObjectPtr<UCharacterMovementComponent> MovementComponent;

private:
	TObjectPtr<ARGGBaseCharacter> BaseCharacter;
	
	
};
