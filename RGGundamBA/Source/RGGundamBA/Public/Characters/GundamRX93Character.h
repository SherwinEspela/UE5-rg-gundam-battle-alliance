// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RGGBaseCharacter.h"
#include "GundamRX93Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ARX93Rifle;
class ARX93Shield;
class URX93AnimInstance;
class UGroundHeightDetectorAC;
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
	void MovementStopped(bool Value);
	void Jump() override;

protected:
	virtual void BeginPlay() override;
	virtual void AttachWeapons();

	UFUNCTION(BlueprintCallable)
	void HandleReachedJumpApex();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	UCameraComponent* FollowCamera;

	URX93AnimInstance* RX93AnimInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Ground Height Detector")
	UGroundHeightDetectorAC* GroundHeightDetector;

protected:
	// Weapons
	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<ARX93Rifle> RifleClass;

	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<ARX93Shield> ShieldClass;

	TObjectPtr<ARX93Rifle> Rifle;
	TObjectPtr<ARX93Shield> Shield;
};
