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
class UJumpGravityController;
class UThrusterVfxController;
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

	UFUNCTION()
	void HandleDistanceToGroundReached();

	void SetThrusterVFXActive(bool Value);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera Property")
	UCameraComponent* FollowCamera;

	URX93AnimInstance* RX93AnimInstance;

protected:
	// Actor Components

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Ground Height Detector")
	UGroundHeightDetectorAC* GroundHeightDetector;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Jump Gravity Controller")
	UJumpGravityController* JumpGravityController;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "VFX")
	UThrusterVfxController* ThrusterVfxController;

protected:
	// VFX

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXBackpackFXLT;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXBackpackFXRT;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXBackpackFXLB;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXBackpackFXRB;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXCalfFXL;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXCalfFXR;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXFootFXL;

	UPROPERTY(EditAnywhere, Category = Effects)
	UParticleSystemComponent* FXFootFXR;

protected:
	// Weapons

	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<ARX93Rifle> RifleClass;

	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<ARX93Shield> ShieldClass;

	TObjectPtr<ARX93Rifle> Rifle;
	TObjectPtr<ARX93Shield> Shield;

};
