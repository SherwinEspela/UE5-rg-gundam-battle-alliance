// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/RGGWeaponActor.h"
#include "RX93Rifle.generated.h"

class UStaticMeshComponent;

/**
 * 
 */
UCLASS()
class RGGUNDAMBA_API ARX93Rifle : public ARGGWeaponActor
{
	GENERATED_BODY()
public:
	ARX93Rifle();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> Mesh;
};
