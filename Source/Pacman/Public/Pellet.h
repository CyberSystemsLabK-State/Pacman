// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Pellet.generated.h"

UCLASS()
class PACMAN_API APellet : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APellet();
	UPROPERTY(EditDefaultsOnly, Category = "Collectable")
	UStaticMeshComponent* PelletMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Collectable")
	USphereComponent* BaseCollisionComponent;
	UPROPERTY(EditAnywhere, Category = "Collectable")
	bool isBluePill;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
/*
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
*/
};
