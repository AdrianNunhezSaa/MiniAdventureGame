// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController_CXX.h"
#include "CubeColor_CXX.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AMyPlayerController_CXX::AMyPlayerController_CXX()
{
}

void AMyPlayerController_CXX::BeginPlay()
{
	Super::BeginPlay();

	//Getting all actors of class
	TArray<AActor*> foundObjects;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACubeColor_CXX::StaticClass(), foundObjects);

	UE_LOG(LogTemp, Warning, TEXT("The total number of CubeColor_CXX class in the level is/are: %d"), foundObjects.Num());

	int index = 0;
	for (auto a : foundObjects) {
		cubesColor_array.Add(Cast<ACubeColor_CXX>(a));
		UE_LOG(LogTemp, Warning, TEXT("Item with name: %s"), *foundObjects[index]->GetName());
		index++;
	}
}

