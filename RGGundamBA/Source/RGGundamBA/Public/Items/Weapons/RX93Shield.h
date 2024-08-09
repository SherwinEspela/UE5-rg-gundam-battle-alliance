// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/RGGWeaponActor.h"
#include "RX93Shield.generated.h"

class USkeletalMeshComponent;

/**
 * 
 */
UCLASS()
class RGGUNDAMBA_API ARX93Shield : public ARGGWeaponActor
{
	GENERATED_BODY()
	
public:
	ARX93Shield();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Shield Mesh")
	TObjectPtr<USkeletalMeshComponent> Mesh;

};
