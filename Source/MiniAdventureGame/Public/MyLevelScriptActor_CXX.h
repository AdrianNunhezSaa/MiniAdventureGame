// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MyLevelScriptActor_CXX.generated.h"

class ACubeColor_CXX;

UCLASS()
class MINIADVENTUREGAME_API AMyLevelScriptActor_CXX : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	TArray<ACubeColor_CXX*> cubesColor_array;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
