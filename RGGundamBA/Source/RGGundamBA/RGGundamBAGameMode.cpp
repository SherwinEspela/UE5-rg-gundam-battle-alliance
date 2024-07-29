// Copyright Epic Games, Inc. All Rights Reserved.

#include "RGGundamBAGameMode.h"
#include "RGGundamBACharacter.h"
#include "UObject/ConstructorHelpers.h"

ARGGundamBAGameMode::ARGGundamBAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
