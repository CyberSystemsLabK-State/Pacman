// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanCharacter.h"
#include "EngineUtils.h"

// Sets default values
APacmanCharacter::APacmanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(true);

	// initialise UCapsuleComponent
	capsule_component = CreateDefaultSubobject<UCapsuleComponent>(TEXT("capsule_component"));
	capsule_component->SetupAttachment(RootComponent);
	// static mesh for rendered model
	mesh_component = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh_component"));
	mesh_component->SetupAttachment(RootComponent);
	// test component to check if Pacman functionality works
	// to be removed and changed to top-down PoV
	player_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("player_camera"));
	player_camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APacmanCharacter::BeginPlay() {

	/*
	if (GetWorld()->GetFirstPlayerController() != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PlayerController exists."));
		GetWorld()->GetFirstPlayerController()->Possess(this);
	}
	*/

	Super::BeginPlay();

	lives = 3;
	start_point = GetActorLocation();

	/*
	* set collision handler
	* UE4 handles this in a single line, but UE5 needs this to store UCapsuleComponent() in a memory space
	* only then can we call the next line.
	*/

	// Bind pacman event handler to collsion component overlap
	// i.e. Pacman overlaps with pellet or ghost
	capsule_component->OnComponentBeginOverlap.AddDynamic(this, &APacmanCharacter::OnCollision);

	// find total pellet count in the map
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PacmanCharacter: Pacman Character Spawned."));
}

// Called every frame
void APacmanCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APacmanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// player movement inputs
	PlayerInputComponent->BindAxis(TEXT("MoveX"), this, &APacmanCharacter::MoveYAxis);
	PlayerInputComponent->BindAxis(TEXT("MoveY"), this, &APacmanCharacter::MoveXAxis);

	// camera movement inputs
	PlayerInputComponent->BindAxis(TEXT("PanX"), this, &APacmanCharacter::PanXAxis);
	PlayerInputComponent->BindAxis(TEXT("PanY"), this, &APacmanCharacter::PanYAxis);

	// player rotation inputs
	PlayerInputComponent->BindAction(TEXT("FaceNorth"), IE_Pressed, this, &APacmanCharacter::FaceNorth);
	PlayerInputComponent->BindAction(TEXT("FaceSouth"), IE_Pressed, this, &APacmanCharacter::FaceSouth);
	PlayerInputComponent->BindAction(TEXT("FaceEast"), IE_Pressed, this, &APacmanCharacter::FaceEast);
	PlayerInputComponent->BindAction(TEXT("FaceWest"), IE_Pressed, this, &APacmanCharacter::FaceWest);

	// player event inputs
	PlayerInputComponent->BindAction(TEXT("NewGame"), IE_Pressed, this, &APacmanCharacter::NewGame);
	PlayerInputComponent->BindAction(TEXT("PauseGame"), IE_Pressed, this, &APacmanCharacter::PauseGame);
	PlayerInputComponent->BindAction(TEXT("RestartGame"), IE_Pressed, this, &APacmanCharacter::RestartGame);
}

// FIX: constant velocity applied until a wall is hit.
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

void APacmanCharacter::PanXAxis(float axis_value) {
	AddControllerPitchInput(axis_value);
	return;
}

void APacmanCharacter::PanYAxis(float axis_value) {
	AddControllerYawInput(axis_value);
	return;
}

// input handlers to rotate pacman model in current direction
// test handlers; remember to fix
// Works fine as is; *could* be refactored to one method but would end up being complex
void APacmanCharacter::FaceNorth() {
	SetActorRotation(FRotator(0.f, 0.f, 0.f));
	mesh_component->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
}

void APacmanCharacter::FaceSouth() {
	SetActorRotation(FRotator(0.f, 180.f, 0.f));
	mesh_component->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));
}

void APacmanCharacter::FaceEast() {
	SetActorRotation(FRotator(0.f, 90.f, 0.f));
	mesh_component->SetRelativeRotation(FRotator(0.f, 90.f, 0.f));
}

void APacmanCharacter::FaceWest() {
	SetActorRotation(FRotator(0.f, 270.f, 0.f));
	mesh_component->SetRelativeRotation(FRotator(0.f, 270.f, 0.f));
}


//Game event handlers
void APacmanCharacter::NewGame() {
	/*if (game_mode->GetCurrentState() == EGameState::EMenu) {
		game_mode->SetCurrentState(EGameState::EPlaying);
	}*/
	return;
}

void APacmanCharacter::PauseGame() {
	/*if (game_mode->GetCurrentState() == EGameState::EPlaying) {
		game_mode->SetCurrentState(EGameState::EPause);
	}
	else if (game_mode->GetCurrentState() == EGameState::EPause) {
		game_mode->SetCurrentState(EGameState::EPlaying);
	}*/
	return;
}

void APacmanCharacter::RestartGame() {
	GetWorld()->GetFirstPlayerController()->ConsoleCommand(TEXT("RestartLevel"));
	return;
}

// coliision handler

void APacmanCharacter::OnCollision
(UPrimitiveComponent* overlapped_component,
	AActor* other_actor, UPrimitiveComponent* other_component, int32 other_body_index,
	bool b_from_sweep, const FHitResult& sweep_result) {
	//// checks if game is currently running
	//if (game_mode->GetCurrentState() != EGameState::EPlaying) {
	//	return;
	//}
	//
	//// BUG: AActor->IsA() returns APellet::StaticClass() as a non-existent class 
	if (!other_actor->IsA(APellet::StaticClass())) {
		return;
	}
	
	//// checks if pellet to be eaten will trigger win condition
	//if (--total_pellets == 0) {
	//	game_mode->SetCurrentState(EGameState::EWin);
	//}
	other_actor->Destroy();
	return;
}

// handles pacman death
void APacmanCharacter::Kill() {
	/*if (--lives == 0) {
		game_mode->SetCurrentState(EGameState::EGameOver);
	}
	else {
		SetActorLocation(start_point);
	}*/
}