// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RGGBasePlayerController.generated.h"

class AGundamRX93Character;
class UInputMappingContext;
class UInputAction;
class UCommandsWidget;
class UEnhancedInputComponent;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class RGGUNDAMBA_API ARGGBasePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	AGundamRX93Character* PlayerCharacter;
	UEnhancedInputComponent* EnhancedInputComponent;

protected:
	// Player Inputs
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Player Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Player Input")
	UInputAction* LookAction;

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
};
