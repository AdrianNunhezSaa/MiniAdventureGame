// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase_CXX.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class USphereComponent;
class UMaterial;

UCLASS()
class MINIADVENTUREGAME_API AItemBase_CXX : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase_CXX();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* staticMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphereCollision;

	UFUNCTION(BlueprintCallable)
	virtual void onUse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
