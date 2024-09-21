// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ConvertToDataTableGISubSystem.generated.h"

/**
 * 
 */
UCLASS()
class CSVTODATATABLESAMPLE_API UConvertToDataTableGISubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	UFUNCTION(BlueprintCallable,Category="Load")
	class UDataTable* LoadDataTableFromCsv(const FString& InFilePath);
};
