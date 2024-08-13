// Copyright 2024 Sherwin Espela. All rights reserved.


#include "ActorComponents/JumpGravityController.h"
#include "Curves/CurveFloat.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "Characters/GundamRX93Character.h"

UJumpGravityController::UJumpGravityController()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UJumpGravityController::BeginPlay()
{
	Super::BeginPlay();
	
	bCanAdjustGravity = false;
	AGundamRX93Character* Gundam = CastChecked<AGundamRX93Character>(GetOwner());
	CharacterMovement = Gundam->GetCharacterMovement();
	CharacterMovement->GravityScale = GravityScaleReset;
}

void UJumpGravityController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CharacterMovement)
	{
		if (bJumpStarted && CharacterMovement->GravityScale > 1.0f)
		{
			CharacterMovement->GravityScale -= GravityScaleDecreaseRate;
		}
		else if (bJumpApexReached)
		{
			CharacterMovement->GravityScale += GravityScaleIncreaseRate;
		}
	}
}

void UJumpGravityController::HandleJumpStarted()
{
	CharacterMovement->GravityScale = GravityScaleReset;
	bJumpStarted = true;
}

void UJumpGravityController::HandleJumpApexReached()
{
	bJumpStarted = false;
	CharacterMovement->GravityScale = 1.f;
	bJumpApexReached = true;
}

void UJumpGravityController::Reset()
{
	bJumpStarted = false;
	bJumpApexReached = false;
	CharacterMovement->GravityScale = GravityScaleReset;
}
