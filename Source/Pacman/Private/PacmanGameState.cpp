// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanGameState.h"

APacmanGameState::APacmanGameState() {
	return;
}

void APacmanGameState::SetGameState(EGameState new_state) {
	game_state = new_state;
	return;
}

