// Fill out your copyright notice in the Description page of Project Settings.


#include "RGGAAnimations/RX93AnimInstance.h"

void URX93AnimInstance::MovementStopped(bool Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("MoveStopped..."));
	if (Value)
	{
		HandleMovementStopped();
	}
	
	bIsMovementStopped = Value;
}
