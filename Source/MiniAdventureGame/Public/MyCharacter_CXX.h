// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyCharacter_CXX.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;

UCLASS()
class MINIADVENTUREGAME_API AMyCharacter_CXX : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter_CXX();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotationRate;

	UFUNCTION(BlueprintCallable)
	void On_Interact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* camera;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* movementComponent;

	void On_MovementHorizontal(float axisValue);
	void On_MovementVertical(float axisValue);
	void On_RotateHorizontal(float axisValue);
	void On_RotateVertical(float axisValue);
};
