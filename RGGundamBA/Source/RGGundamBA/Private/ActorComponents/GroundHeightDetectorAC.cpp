// Copyright 2024 Sherwin Espela. All rights reserved.


#include "ActorComponents/GroundHeightDetectorAC.h"

#define DISTANCE_OFFSET 913.249207f
#define DISTANCE_RESET 10000.0f

UGroundHeightDetectorAC::UGroundHeightDetectorAC()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGroundHeightDetectorAC::BeginPlay()
{
	Super::BeginPlay();
	Reset();
}

void UGroundHeightDetectorAC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bCanMeasure)
	{
		CheckDistanceToGroundByLineTrace();
	}
}

void UGroundHeightDetectorAC::MeasureGroundDistance()
{
	bCanMeasure = true;
}

void UGroundHeightDetectorAC::Reset()
{
	bCanMeasure = false;
	DistanceToGround = DISTANCE_RESET;
}

void UGroundHeightDetectorAC::CheckDistanceToGroundByLineTrace()
{
	FVector LineTraceStart = GetOwner()->GetActorLocation();
	FVector LineTraceEnd = LineTraceStart + (GetOwner()->GetActorUpVector() * -1 * 5000.f);

	FHitResult Hit;
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(GetOwner());
	const bool bHitSuccess = GetWorld()->LineTraceSingleByChannel(
		Hit, LineTraceStart, LineTraceEnd, ECollisionChannel::ECC_Pawn, CollisionQueryParams
	);

	if (bHitSuccess)
	{
		float Distance = FVector::Distance(LineTraceStart, Hit.ImpactPoint);
		DistanceToGround = Distance - DISTANCE_OFFSET;

		if (bIsDebugging)
		{
			DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 100.f, 30.f, FColor::Red, false);
			DrawDebugSphere(GetWorld(), LineTraceStart, 100.f, 30.f, FColor::Green, false);
			DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Red, false);
			UE_LOG(LogTemp, Warning, TEXT("DistanceToGround === %f"), DistanceToGround);
		}
		
		if (DistanceToGround <= 0.f || DistanceToGround <= 0.1f)
		{
			Reset();
			OnDistanceToGroundReached.Broadcast();
		}
	}
}

