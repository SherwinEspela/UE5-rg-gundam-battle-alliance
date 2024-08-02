// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RGGBaseCharacter.h"
#include "GundamRX93Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class RGGUNDAMBA_API AGundamRX93Character : public ARGGBaseCharacter
{
	GENERATED_BODY()
	
public:
	AGundamRX93Character();

public:
	// Player Actions and Movement
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	UCameraComponent* FollowCamera;
};
