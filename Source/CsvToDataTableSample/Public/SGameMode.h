// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CSVTODATATABLESAMPLE_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere,Category="DataTable",BlueprintReadWrite)
	TObjectPtr<class UDataTable> DataTable;
};
