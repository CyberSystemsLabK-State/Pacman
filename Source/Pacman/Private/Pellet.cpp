// Fill out your copyright notice in the Description page of Project Settings.


#include "Pellet.h"

// Sets default values
APellet::APellet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetActorEnableCollision(true);

	BaseCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("BaseCollisionComponent"));
	PelletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PelletMesh"));
	PelletMesh->SetupAttachment(BaseCollisionComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("StaticMesh'/Script/Engine.StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere''"));
	
	if (Sphere.Succeeded()) {
		PelletMesh->SetStaticMesh(Sphere.Object);
	}
}

// Called when the game starts or when spawned
void APellet::BeginPlay()
{
	Super::BeginPlay();

	if (isBluePill == true) {
		PelletMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
		BaseCollisionComponent->SetSphereRadius(50);
	}
	else {
		PelletMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
		BaseCollisionComponent->SetSphereRadius(25);
	}
	
}

/*
// Called every frame
void APellet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

