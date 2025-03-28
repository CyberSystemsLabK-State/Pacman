// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanGameMode.h"

APacmanGameMode::APacmanGameMode() {

	game_state = CreateDefaultSubobject<APacmanGameState>(TEXT("game_state"));
	return;
}

void APacmanGameMode::SetCurrentState(EGameState state_value) {
	game_state->SetGameState(state_value);
	return;
}



