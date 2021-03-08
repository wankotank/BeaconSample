// Fill out your copyright notice in the Description page of Project Settings.


#include "MyOnlineBeaconStateBase.h"
#include "MyOnlineBeaconClientBase.h"

AMyOnlineBeaconStateBase::AMyOnlineBeaconStateBase(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	bReplicates = true;
	bAlwaysRelevant = true;
	NetDriverName = NAME_BeaconNetDriver;
}

bool AMyOnlineBeaconStateBase::IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const
{
	UClass* BeaconClass = RealViewer->GetClass();
	return (BeaconClass && BeaconClass->IsChildOf(AMyOnlineBeaconClientBase::StaticClass()));
}
