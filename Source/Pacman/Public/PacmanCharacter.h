// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PacmanGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "PacmanCharacter.generated.h"

UCLASS()
class PACMAN_API APacmanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APacmanCharacter();

private:
	FVector current_velocity;
	APacmanGameMode* game_mode;

	// movement handlers
	void MoveXAxis(float axis_value);
	void MoveYAxis(float axis_value);

	// game events
	void NewGame();
	void PauseGame();
	void RestartGame();

	UFUNCTION()
	void OnCollision(class AActor* other_actor, class UPrimiviteComponent* other_component, int32 other_body_index);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
