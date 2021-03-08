// Copyright Epic Games, Inc. All Rights Reserved.

#include "BeaconSampleGameMode.h"
#include "BeaconSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABeaconSampleGameMode::ABeaconSampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
