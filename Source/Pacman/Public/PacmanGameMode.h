// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"
#include "TimerManager.h"

#include "PacmanPlayerController.h""
#include "PacmanCharacter.h"
#include "PacmanGameState.h"
#include "Pellet.h"

#include "PacmanGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacmanGameMode : public AGameMode
{
	GENERATED_BODY()
private:
	UPROPERTY()
	APacmanGameState* game_state;
	int pellet_count;

protected:
	virtual void StartPlay() override;

public:
	// Constructor
	APacmanGameMode();
	//Default destructor
	virtual ~APacmanGameMode() = default; 

	EGameState GetCurrentState() const;
	void SetCurrentState(EGameState state_value);

	uint8 GetPelletCount();
};
