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
	// gets active pellet count
	// will count anything using or inheriting AActor, including non-pellet actors
	// BUG: returns 0; need
	pellet_count = (uint8_t)(GetWorld()->GetActorCount());

	for (TActorIterator<APellet> PelletItr(GetWorld()); PelletItr; ++PelletItr) {
		pellet_count++;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, GetWorld()->GetDebugDisplayName());

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PacmanGameMode: StartPlay called."));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(
		TEXT("PacmanGameMode: Current state - %f."), GetCurrentState()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(
		TEXT("PacmanGameMode: %f pellets spawned."), pellet_count));


	Super::StartPlay();

	
}

uint8 APacmanGameMode::GetPelletCount() {
	return pellet_count;
	
}

