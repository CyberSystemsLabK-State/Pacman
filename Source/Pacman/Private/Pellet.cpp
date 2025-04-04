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
		PelletMesh->SetWorldScale3D(FVector(0.7, 0.7, 0.7));

		BaseCollisionComponent->SetSphereRadius(36);
	}
}

// Called when the game starts or when spawned
void APellet::BeginPlay()
{
	Super::BeginPlay();
	
}

/*
// Called every frame
void APellet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

