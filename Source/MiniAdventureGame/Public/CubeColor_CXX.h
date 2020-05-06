// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase_CXX.h"
#include "CubeColor_CXX.generated.h"

class UMaterial;
class UMaterialInstance;

UCLASS()
class MINIADVENTUREGAME_API ACubeColor_CXX : public AItemBase_CXX
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ACubeColor_CXX();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void onUse() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString myColor;

	UFUNCTION(BlueprintCallable)
	void swapMaterial();

	UMaterialInstance* material_copy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UMaterialInstance* material_inst;
	TArray<UMaterialInstance*> colors_array;
	int color_index;
	TArray<FString> colors_name_array = {"Blue","Red","Green"};
	TArray<ACubeColor_CXX*> allCubesColor_array;
};
