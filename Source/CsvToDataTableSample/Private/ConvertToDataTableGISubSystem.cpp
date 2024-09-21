// Fill out your copyright notice in the Description page of Project Settings.


#include "ConvertToDataTableGISubSystem.h"

#include "MyStructs.h"
#include "Engine/DataTable.h"

void UConvertToDataTableGISubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

UDataTable* UConvertToDataTableGISubSystem::LoadDataTableFromCsv(const FString& InFilePath)
{
	if(!FPaths::FileExists(InFilePath))
	{
		UE_LOG(LogTemp,Warning,TEXT("Does not here: %s"),*InFilePath);
		return nullptr;
	}

	TArray<FString> Contents;

	if(!FFileHelper::LoadFileToStringArray(Contents,*InFilePath))
	{
		UE_LOG(LogTemp,Warning,TEXT("Failed to read file: %s"),*InFilePath);
		return nullptr;
	}

	TObjectPtr<UDataTable> DataTable = NewObject<UDataTable>();
	DataTable->RowStruct = FDataSample::StaticStruct();
	// TArray<FString> OutProblems =  DataTable->CreateTableFromCSVString(Content);
	// if(OutProblems.Num()>0)
	// {
	// 	UE_LOG(LogTemp,Error,TEXT("Failed to create from Csv File"));
	//
	// 	for(const FString& Problem : OutProblems)
	// 	{
	// 		UE_LOG(LogTemp,Error,TEXT("%s"),*Problem);
	// 	}
	// 	return nullptr;
	// }

	for(int32 i = 1;i<Contents.Num();i++)
	{
		FString Content = Contents[i];
		TArray<FString> ParsedData;
		Content.ParseIntoArray(ParsedData,TEXT(","),true);

		FVector Pos = FVector(FCString::Atof(*ParsedData[0]) ,FCString::Atof(*ParsedData[1]),FCString::Atof(*ParsedData[2]));
		
		FDataSample DataSample = FDataSample(Pos);
		FName RowName = *FString::Printf(TEXT("Row_%d"),i);
		
		DataTable->AddRow(RowName,DataSample);
	}
	UE_LOG(LogTemp,Log,TEXT("DataTable loaded successfully from %s"),*InFilePath);
	return DataTable;
}
