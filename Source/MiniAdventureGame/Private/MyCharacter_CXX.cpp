// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter_CXX.h"
#include "CubeColor_CXX.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define COLLISION_ITEM ECC_GameTraceChannel1

// Sets default values
AMyCharacter_CXX::AMyCharacter_CXX()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Camera Rotation Rate
	rotationRate = 25;

	//Creating Components
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	movementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

	//Attach Components
	RootComponent = springArm;
	camera->SetupAttachment(springArm);

	//Components Properties
	springArm->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = true;

}

// Called when the game starts or when spawned
void AMyCharacter_CXX::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AMyCharacter_CXX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter_CXX::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Action
	PlayerInputComponent->BindAction("Use", EInputEvent::IE_Pressed, this, &AMyCharacter_CXX::On_Interact);

	//Axis
	PlayerInputComponent->BindAxis("Move_Horizontal", this, &AMyCharacter_CXX::On_MovementHorizontal);
	PlayerInputComponent->BindAxis("Move_Vertical", this, &AMyCharacter_CXX::On_MovementVertical);
	PlayerInputComponent->BindAxis("Rotate_Horizontal", this, &AMyCharacter_CXX::On_RotateHorizontal);
	PlayerInputComponent->BindAxis("Rotate_Vertical", this, &AMyCharacter_CXX::On_RotateVertical);

}

//Called when A,D is used
void AMyCharacter_CXX::On_MovementHorizontal(float axisValue)
{
	AddMovementInput(GetActorRightVector(), axisValue, false);
}

//Called when W,S is used
void AMyCharacter_CXX::On_MovementVertical(float axisValue)
{
	AddMovementInput(GetActorForwardVector(), axisValue, false);
}

//Called when rotate yaw spring arm
void AMyCharacter_CXX::On_RotateHorizontal(float axisValue)
{
	AddControllerYawInput(axisValue * rotationRate * GetWorld()->GetDeltaSeconds());
}

//Called when rotate pitch spring arm
void AMyCharacter_CXX::On_RotateVertical(float axisValue)
{
	AddControllerPitchInput(axisValue * rotationRate * GetWorld()->GetDeltaSeconds());
}

//Called when Left Click is used
void AMyCharacter_CXX::On_Interact()
{
	//Trace vars
	float startTraceDistance = 4;
	float endTraceDistance = 250;

	FHitResult hitResult;
	FCollisionQueryParams traceParams;

	FVector startTrace = GetActorLocation() + camera->GetForwardVector() * startTraceDistance;
	FVector endTrace = GetActorLocation() + camera->GetForwardVector() * endTraceDistance;
	
	//Line trace
	DrawDebugLine(GetWorld(), startTrace, endTrace, FColor::Orange, false, 2.0f, 0, 1.0f);
	if (GetWorld()->LineTraceSingleByChannel(hitResult, startTrace, endTrace, COLLISION_ITEM, traceParams)){

		//Comprobate that the actor is a CubeColor and create a ref to use it
		if (ACubeColor_CXX * refCubeColor = Cast<ACubeColor_CXX>(hitResult.GetActor())) {
			refCubeColor->onUse();
			//refCubeColor->swapMaterial();
		}				
		else
			UE_LOG(LogTemp, Warning, TEXT("Im not a CubeColor_CXX class"));

	}
}