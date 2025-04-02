// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PacmanGameState.generated.h"

enum class EGameState : short {
	EMenu,
	EPlaying,
	EPause,
	EWin,
	EGameOver
};

/**
 * 
 */
UCLASS()
class PACMAN_API APacmanGameState : public AGameState
{
	GENERATED_BODY()
private:
	EGameState game_state;
	uint8 total_pellets; // totals spawned pellets

public:
	// constructor
	APacmanGameState();
	// default destructor
	virtual ~APacmanGameState() = default;

	// inline definition due to being const
	// dunno why O'Reilly didn't check that
	EGameState GetGameState() const;
	void SetGameState(EGameState new_state);
	

};
