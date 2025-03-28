// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PacmanGameMode.h"
// included for Pacman->Pellet collisions
#include "Pellet.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "PacmanCharacter.generated.h"

UCLASS()
class PACMAN_API APacmanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// why does UE5 put the constructor in a separate modifier indent?
	// Sets default values for this character's properties
	APacmanCharacter();

private:
	FVector current_velocity;	// vector of pacman velocities
	FVector start_point;	// pacman start point
	APacmanGameMode* game_mode;
	UCapsuleComponent* capsule_component;

	uint8 total_pellets; // no. of pellets for win condition
	uint8 lives; // total player lives

	// movement handlers
	void MoveXAxis(float axis_value);
	void MoveYAxis(float axis_value);

	// game events
	void NewGame();
	void PauseGame();
	void RestartGame();

	// BUG: see src commment. Parameters should match (UPrimitiveComponent*, AActor*, UPrimitiveComponent*, 
	// int32, bool, const FHitResult &)
	UFUNCTION()
	void OnCollision(AActor* other_actor, UPrimitiveComponent* other_component, int32 other_body_index);	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
