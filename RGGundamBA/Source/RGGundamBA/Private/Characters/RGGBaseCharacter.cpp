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
	
}

void ARGGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARGGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

