// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
// included for Pacman->Pellet collisions
#include "Pellet.h"
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
	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* capsule_component;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* mesh_component;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* player_camera;

	uint8 total_pellets; // no. of pellets for win condition
	uint8 lives; // total player lives

	// movement handlers
	void MoveXAxis(float axis_value);
	void MoveYAxis(float axis_value);

	// rotation handlers
	void FaceNorth();
	void FaceSouth();
	void FaceEast();
	void FaceWest();

	// game events
	void NewGame();
	void PauseGame();
	void RestartGame();

	// Pacman death handler
	void Kill();

	// Pacman collision event handler
	UFUNCTION()
	void OnCollision(UPrimitiveComponent* overlapped_component,
		AActor* other_actor, UPrimitiveComponent* other_component, int32 other_body_index,
		bool b_from_sweep, const FHitResult& sweep_result);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
