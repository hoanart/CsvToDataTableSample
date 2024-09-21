// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "MyStructs.generated.h"

USTRUCT(BlueprintType)
struct FDataSample : public FTableRowBase
{
	GENERATED_BODY()
	FDataSample() = default;

	FDataSample(FVector InPosition)
		:Position(InPosition)
	{}
	
	UPROPERTY(VisibleAnywhere,Category="Data")
	FVector Position;
};
USTRUCT(BlueprintType)
struct FDataSTSample : public FTableRowBase
{
	GENERATED_BODY()
	FDataSTSample() = default;

	FDataSTSample(float InPositionX,float InPositionY,float InPositionZ)
		: PositionX(InPositionX)
		, PositionY(InPositionY)
		, PositionZ(InPositionZ)
	{}
	
	UPROPERTY(VisibleAnywhere,Category="Data")
	float PositionX;
	UPROPERTY(VisibleAnywhere,Category="Data")
	float PositionY;
	UPROPERTY(VisibleAnywhere,Category="Data")
	float PositionZ;
};
/**
 * 
 */
UCLASS()
class CSVTODATATABLESAMPLE_API UMyStructs : public UObject
{
	GENERATED_BODY()
	
};
