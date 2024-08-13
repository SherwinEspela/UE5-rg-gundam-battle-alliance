// Copyright 2024 Sherwin Espela. All rights reserved.


#include "ActorComponents/GroundHeightDetectorAC.h"

#define DISTANCE_OFFSET 913.249207f

UGroundHeightDetectorAC::UGroundHeightDetectorAC()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGroundHeightDetectorAC::BeginPlay()
{
	Super::BeginPlay();

	bCanMeasure = false;
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
		DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 100.f, 30.f, FColor::Red, false);
		DrawDebugSphere(GetWorld(), LineTraceStart, 100.f, 30.f, FColor::Green, false);
		DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Red, false);
		float Distance = FVector::Distance(LineTraceStart, Hit.ImpactPoint);
		
		DistanceToGround = Distance - DISTANCE_OFFSET;
		//UE_LOG(LogTemp, Warning, TEXT("DistanceToGround === %f"), DistanceToGround);
		if (DistanceToGround <= 0.f)
		{
			bCanMeasure = false;
			DistanceToGround = DISTANCE_OFFSET;
		}

		// apex to ground value = 510.320129
	}
}

