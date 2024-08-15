// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enums/MovementStatesEnum.h"
#include "RGGBaseCharacter.generated.h"

UCLASS()
class RGGUNDAMBA_API ARGGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARGGBaseCharacter();

public:
	FORCEINLINE void SetMovementState(EMovementStates Value) { MovementState = Value; }

protected:
	virtual void BeginPlay() override;

protected:
	EMovementStates MovementState;
};
