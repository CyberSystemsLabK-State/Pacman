// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "PacmanCharacter.h"

#include "PacmanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacmanPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay();

public:
	APacmanPlayerController();
	// default destructor
	virtual ~APacmanPlayerController() = default;
	void MovementInput();
};
