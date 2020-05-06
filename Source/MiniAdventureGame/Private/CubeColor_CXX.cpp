// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeColor_CXX.h"
#include "Materials/MaterialInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController_CXX.h"

ACubeColor_CXX::ACubeColor_CXX()
{
	//Find the material instance (Copy Ref from editor)
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> blueMaterial(TEXT("MaterialInstanceConstant'/Game/GameContent/Materials/MAT_Cube_Color_Inst_Blue.MAT_Cube_Color_Inst_Blue'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> redMaterial(TEXT("MaterialInstanceConstant'/Game/GameContent/Materials/MAT_Cube_Color_Inst_Red.MAT_Cube_Color_Inst_Red'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> greenMaterial(TEXT("MaterialInstanceConstant'/Game/GameContent/Materials/MAT_Cube_Color_Inst_Green.MAT_Cube_Color_Inst_Green'"));

	//Add the finded material instances to the array, casted
	if ((blueMaterial.Object != NULL) && (redMaterial.Object != NULL) && (greenMaterial.Object != NULL))
	{	
		colors_array.Add((UMaterialInstance*)blueMaterial.Object);
		colors_array.Add((UMaterialInstance*)redMaterial.Object);
		colors_array.Add((UMaterialInstance*)greenMaterial.Object);
	}

	color_index = 0;
}

// Called when the game starts or when spawned
void ACubeColor_CXX::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACubeColor_CXX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACubeColor_CXX::onUse() {

	//Assign the finded material instance to the variable and set the material
	material_inst = colors_array[color_index];
	staticMesh->SetMaterial(0, material_inst);

	UE_LOG(LogTemp, Warning, TEXT("Im the item with name: %s"), *GetName());
	UE_LOG(LogTemp, Warning, TEXT("And my colour is: %s"), *colors_name_array[color_index]);
	
	//Array to change color
	if (color_index < colors_array.Num() - 1)
		color_index++;
	else
		color_index = 0;
}

void ACubeColor_CXX::swapMaterial()
{
	//Use player controller to access all itemColorCubes, previously stored
	AMyPlayerController_CXX* myPlayerController = Cast<AMyPlayerController_CXX>(UGameplayStatics::GetPlayerController(this, 0));

	if (myPlayerController) {

		int index = 0;
		for (auto a : myPlayerController->cubesColor_array) {
			if (myPlayerController->cubesColor_array[index]->GetName() == this->GetName()) {

				if (index == myPlayerController->cubesColor_array.Num() -1){
					material_copy = (UMaterialInstance*)myPlayerController->cubesColor_array[0]->staticMesh->GetMaterial(0);
					staticMesh->SetMaterial(0, material_copy);
				}
				else {
					material_copy = (UMaterialInstance*)myPlayerController->cubesColor_array[index + 1]->staticMesh->GetMaterial(0);
					staticMesh->SetMaterial(0, material_copy);
				}

			}else
				index++;
		}
	}
	
}