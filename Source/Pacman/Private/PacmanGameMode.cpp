// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanGameMode.h"

APacmanGameMode::APacmanGameMode() {
	
	// Sets GameMode to use custom GameState; otherwise defaults to GameStateBase
	GameStateClass = APacmanGameState::StaticClass();

	game_state = CreateDefaultSubobject<APacmanGameState>(TEXT("game_state"));
	return;
}

EGameState APacmanGameMode::GetCurrentState() const {

	return game_state->GetGameState();
}

void APacmanGameMode::SetCurrentState(EGameState state_value) {
	game_state->SetGameState(state_value);
	return;
}

void APacmanGameMode::StartPlay() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PacmanGameMode: StartPlay called."));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(
		TEXT("PacmanGameMode: Current state - %f."), GetCurrentState()));

	Super::StartPlay();
}

