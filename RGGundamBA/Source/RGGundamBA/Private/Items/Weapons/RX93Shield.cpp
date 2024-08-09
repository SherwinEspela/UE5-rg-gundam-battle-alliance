// Copyright 2024 Sherwin Espela. All rights reserved.


#include "Items/Weapons/RX93Shield.h"
#include "Components/SkeletalMeshComponent.h"

ARX93Shield::ARX93Shield()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

void ARX93Shield::BeginPlay()
{
	Super::BeginPlay();
}
