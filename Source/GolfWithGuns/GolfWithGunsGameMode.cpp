// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GolfWithGunsGameMode.h"
#include "GolfWithGunsHUD.h"
#include "GolfWithGunsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGolfWithGunsGameMode::AGolfWithGunsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGolfWithGunsHUD::StaticClass();
}
