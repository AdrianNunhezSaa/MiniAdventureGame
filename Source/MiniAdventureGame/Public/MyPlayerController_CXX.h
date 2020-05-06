// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController_CXX.generated.h"

/**
 * 
 */
UCLASS()
class MINIADVENTUREGAME_API AMyPlayerController_CXX : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController_CXX();
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TArray<class ACubeColor_CXX*> cubesColor_array;

};
