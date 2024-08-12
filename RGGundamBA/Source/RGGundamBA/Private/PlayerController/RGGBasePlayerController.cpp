// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/RGGBasePlayerController.h"
#include "Characters/GundamRX93Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

void ARGGBasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<AGundamRX93Character>(GetPawn());
	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContext, 0);
}

void ARGGBasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARGGBasePlayerController::Move);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ARGGBasePlayerController::MoveStopped);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARGGBasePlayerController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ARGGBasePlayerController::Jump);
}

void ARGGBasePlayerController::Move(const FInputActionValue& Value)
{
	PlayerCharacter->Move(Value);
}

void ARGGBasePlayerController::Look(const FInputActionValue& Value)
{
	PlayerCharacter->Look(Value);
}

void ARGGBasePlayerController::MoveStopped(const FInputActionValue& Value)
{
	PlayerCharacter->MovementStopped(true);
}

void ARGGBasePlayerController::Jump()
{
	PlayerCharacter->Jump();
}
