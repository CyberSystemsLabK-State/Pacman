// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanGameMode.h"

APacmanGameMode::APacmanGameMode() {
	
	// Sets GameMode to use custom GameState; otherwise defaults to GameStateBase
	GameStateClass = APacmanGameState::StaticClass();
	DefaultPawnClass = APacmanCharacter::StaticClass();
	PlayerControllerClass = APacmanPlayerController::StaticClass();
	pellet_count = 0;

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
	Super::StartPlay();
	// gets active pellet count
	// will count anything using or inheriting AActor, including non-pellet actors
	// BUG: returns 0; needs

	for (TActorIterator<APellet> PelletItr(GetWorld()); PelletItr; ++PelletItr) {
		pellet_count++;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, GetWorld()->GetDebugDisplayName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PacmanGameMode: StartPlay called."));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(
		TEXT("PacmanGameMode: Current state - %f."), GetCurrentState()));

	if (pellet_count > 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("pellet instances found."));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("no pellet instances found."));
	}
}


uint8 APacmanGameMode::GetPelletCount() {
	return pellet_count;
	
}

