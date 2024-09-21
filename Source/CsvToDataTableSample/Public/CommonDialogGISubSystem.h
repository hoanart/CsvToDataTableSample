// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CommonDialogGISubSystem.generated.h"

/**
 * 
 */
UCLASS()
class CSVTODATATABLESAMPLE_API UCommonDialogGISubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	public:
	void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable,Category="Dialog")
	bool OpenFileDialog(FString& FilePath);

	
};
