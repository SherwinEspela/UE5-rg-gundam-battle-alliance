// Copyright 2024 Sherwin Espela. All rights reserved.


#include "ActorComponents/ThrusterVfxController.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
//#include "Characters/GundamRX93Character.h"
//#include "Components/SkeletalMeshComponent.h"

UThrusterVfxController::UThrusterVfxController()
{
	PrimaryComponentTick.bCanEverTick = true;

	/*FXBackpackThrusterComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FX"));
	USkeletalMeshComponent* Mesh = Cast<AGundamRX93Character>(GetOwner())->GetMesh();
	FXBackpackThrusterComponent->SetupAttachment(Mesh);*/
}

void UThrusterVfxController::BeginPlay()
{
	Super::BeginPlay();

}

void UThrusterVfxController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UThrusterVfxController::PlayBackpackThrusters()
{
	if (FXBackpackThruster1)
	{
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), FXImpact, Hit.Location, ShotDirection.Rotation());
		//UGameplayStatics::SpawnEmitterAttached(FXBackpackThruster1, GetOwner(), FName(""));
	}
}

