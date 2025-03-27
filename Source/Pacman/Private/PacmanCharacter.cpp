// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanCharacter.h"

// Sets default values
APacmanCharacter::APacmanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorEnableCollision(true);

}

// Called when the game starts or when spawned
void APacmanCharacter::BeginPlay()
{
	Super::BeginPlay();
	game_mode = Cast<APacmanGameMode>(UGameplayStatics::GetGameMode(this));
}

// Called every frame
void APacmanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APacmanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// player movement inputs
	PlayerInputComponent->BindAxis(TEXT("MoveX"), this, &APacmanCharacter::MoveYAxis);
	PlayerInputComponent->BindAxis(TEXT("MoveY"), this, &APacmanCharacter::MoveXAxis);
	// player event inputs
	PlayerInputComponent->BindAction(TEXT("NewGame"), IE_Pressed, this, &APacmanCharacter::NewGame);
	PlayerInputComponent->BindAction(TEXT("PauseGame"), IE_Pressed, this, &APacmanCharacter::PauseGame);
	PlayerInputComponent->BindAction(TEXT("RestartGame"), IE_Pressed, this, &APacmanCharacter::RestartGame);

	
	PlayerInputComponent->BindAxis(TEXT("MoveX"), this, &APacmanCharacter::MoveXAxis);
	PlayerInputComponent->BindAxis(TEXT("MoveY"), this, &APacmanCharacter::MoveYAxis);

	PlayerInputComponent->BindAction(TEXT("NewGame"), IE_Pressed, this, &APacmanCharacter::NewGame);
	PlayerInputComponent->BindAction(TEXT("PauseGame"), IE_Pressed, this, &APacmanCharacter::PauseGame);
	PlayerInputComponent->BindAction(TEXT("RestartGame"), IE_Pressed, this, &APacmanCharacter::RestartGame);

}

void APacmanCharacter::MoveXAxis(float axis_value) {
	current_velocity.X = axis_value;
	AddMovementInput(current_velocity);
	return;
}

void APacmanCharacter::MoveYAxis(float axis_value) {
	current_velocity.Y = axis_value;
	AddMovementInput(current_velocity);
	return;
}

//Game event handlers

void APacmanCharacter::NewGame() {
	if (game_mode->GetCurrentState() == EGameState::EMenu) {
		game_mode->SetCurrentState(EGameState::EPlaying);
	}
	return;
}

void APacmanCharacter::PauseGame() {
	if (game_mode->GetCurrentState() == EGameState::EPlaying) {
		game_mode->SetCurrentState(EGameState::EPause);
	}
	else if (game_mode->GetCurrentState() == EGameState::EPause) {
		game_mode->SetCurrentState(EGameState::EPlaying);
	}
	return;
}

void APacmanCharacter::RestartGame() {
	GetWorld()->GetFirstPlayerController()->ConsoleCommand(TEXT("RestartLevel"));
	return;
}