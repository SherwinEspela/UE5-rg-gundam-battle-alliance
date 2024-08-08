// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RGGBaseCharacter.h"
#include "GundamRX93Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ARX93Rifle;
class ARX93Shield;
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
	virtual void AttachWeapons();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	UCameraComponent* FollowCamera;

protected:
	// Weapons
	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<ARX93Rifle> RifleClass;

	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<ARX93Shield> ShieldClass;

	TObjectPtr<ARX93Rifle> Rifle;
	TObjectPtr<ARX93Shield> Shield;
};
