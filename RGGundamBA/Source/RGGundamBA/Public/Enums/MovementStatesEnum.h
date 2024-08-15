// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

UENUM(BlueprintType)
enum class EMovementStates : uint8
{
	EMS_Idle		UMETA(DisplayName = "Idle"),
	EMS_Running		UMETA(DisplayName = "Running"),
	EMS_Jumping		UMETA(DisplayName = "Jumping")
};