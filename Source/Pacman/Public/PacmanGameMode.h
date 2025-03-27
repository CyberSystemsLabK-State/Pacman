// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PacmanGameState.h"
#include "GameFramework/GameMode.h"
#include "PacmanGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacmanGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	APacmanGameMode();
	EGameState GetCurrentState() const {
		return game_state.GetGameState();
	}
	void SetCurrentState(EGameState state_value) {
	}

private:
	APacmanGameState game_state;

	// BUG: cannot override inherit destructor
	//virtual ~APacmanGameMode();
	
};
