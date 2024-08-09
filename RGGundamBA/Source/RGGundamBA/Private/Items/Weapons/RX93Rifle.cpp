// Copyright 2024 Sherwin Espela. All rights reserved.


#include "Items/Weapons/RX93Rifle.h"
#include "Components/StaticMeshComponent.h"

ARX93Rifle::ARX93Rifle()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

void ARX93Rifle::BeginPlay()
{
	Super::BeginPlay();
}
