// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Items/RGGItemActor.h"
#include "Components/StaticMeshComponent.h"

ARGGItemActor::ARGGItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

void ARGGItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}
