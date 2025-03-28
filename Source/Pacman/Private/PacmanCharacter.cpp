// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanCharacter.h"
#include "EngineUtils.h"

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
	game_mode = NewObject<APacmanGameMode>(this, APacmanGameMode::StaticClass());
	game_mode = Cast<APacmanGameMode>(UGameplayStatics::GetGameMode(this));

	/*
	* set collision handler
	* UE4 handles this in a single line, but UE5 needs this to store UCapsuleComponent() in a memory space
	* only then can we call the next line.
	*/

	// BUG: wouldn't ovewriting a pointer cause a memory leak?
	capsule_component = CreateDefaultSubobject<UCapsuleComponent>(TEXT("capsule_component"));
	capsule_component = GetCapsuleComponent();
	// BUG: C2027 - UCapsuleComponent is an undenfined type
	// FIX: Including this in .h may fix it??
	
	// BUG: can't cast delegate function; parameters don't match
	capsule_component->OnComponentBeginOverlap.AddDynamic(this, &APacmanCharacter::OnCollision);

	// find total pellet count in the map
	// PelletItr is an Intellisense error; free to ignore;
	for (TActorIterator<APellet> PelletItr(GetWorld()); PelletItr; ++PelletItr) {
		total_pellets++;
	}
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

// coliision handler

void APacmanCharacter::OnCollision
(AActor* other_actor, UPrimitiveComponent* other_component, int32 other_body_index) {
	// checks if game is currently running
	if (game_mode->GetCurrentState() != EGameState::EPlaying) {
		return;
	}
	
	// BUG: AActor->IsA() returns APellet::StaticClass() as a non-existent class 
	if (!other_actor->IsA(APellet::StaticClass())) {
		return;
	}
	
	// checks if pellet to be eaten will trigger win condition
	if (total_pellets-- == 0) {
		game_mode->SetCurrentState(EGameState::EWin);
	}
	other_actor->Destroy();
	return;
}