// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonDialogGISubSystem.h"

#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"

void UCommonDialogGISubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

bool UCommonDialogGISubSystem::OpenFileDialog(FString& FilePath)
{

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	TArray<FString> FilePaths;
	bool bOpened = false;
	if(DesktopPlatform)
	{
	bOpened =	DesktopPlatform->OpenFileDialog(nullptr,TEXT("파일 찾기"),
			TEXT("D:\\"),TEXT(""),TEXT("CSV Files (*.csv)|*.csv"),EFileDialogFlags::None,FilePaths);
	}
	if(bOpened && FilePaths.Num()>0)
	{
		FilePath = FilePaths[0];
	}
	UE_LOG(LogTemp,Log,TEXT("FILE PATH: %s"),*FilePath);
	return bOpened;
}
