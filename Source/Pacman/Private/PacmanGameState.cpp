// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanGameState.h"

APacmanGameState::APacmanGameState() {
	return;
}

EGameState APacmanGameState::GetGameState() const {
	return game_state;
}

void APacmanGameState::SetGameState(EGameState new_state) {
	game_state = new_state;
	return;
}

