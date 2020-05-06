// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase_CXX.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Materials/Material.h"

#define COLLISION_ITEM ECC_GameTraceChannel1

AItemBase_CXX::AItemBase_CXX()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creating Components
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	sphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));


	//Attach Components
	staticMesh->SetupAttachment(RootComponent);
	sphereCollision->SetupAttachment(staticMesh);

	//Components Properties
	sphereCollision->InitSphereRadius(50);
	sphereCollision->SetCollisionProfileName(TEXT("Trigger"));
	sphereCollision->SetCollisionResponseToChannel(ECollisionChannel::COLLISION_ITEM, ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void AItemBase_CXX::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase_CXX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase_CXX::onUse() {
	
}
