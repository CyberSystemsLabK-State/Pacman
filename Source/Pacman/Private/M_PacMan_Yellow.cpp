// Fill out your copyright notice in the Description page of Project Settings.


#include "M_PacMan_Yellow.h"

// Sets default values
AM_PacMan_Yellow::AM_PacMan_Yellow()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AM_PacMan_Yellow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AM_PacMan_Yellow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AM_PacMan_Yellow::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

