// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Characters/RGGBaseCharacter.h"

// Sets default values
ARGGBaseCharacter::ARGGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARGGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	MovementState = EMovementStates::EMS_Idle;
}
