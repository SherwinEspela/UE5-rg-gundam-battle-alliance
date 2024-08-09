// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RGGItemActor.generated.h"

UCLASS()
class RGGUNDAMBA_API ARGGItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARGGItemActor();

protected:
	virtual void BeginPlay() override;

};
