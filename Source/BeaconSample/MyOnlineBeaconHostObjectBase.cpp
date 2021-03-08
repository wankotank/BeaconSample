// Fill out your copyright notice in the Description page of Project Settings.


#include "MyOnlineBeaconHostObjectBase.h"
#include "OnlineBeaconHost.h"
#include "BeaconSample.h"
#include "OnlineBeaconWorldSubsystem.h"

AMyOnlineBeaconHostObjectBase::AMyOnlineBeaconHostObjectBase(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	ClientBeaconBlueprintClass = ClientBeaconActorClass = AMyOnlineBeaconClientBase::StaticClass();
	BeaconTypeName = ClientBeaconActorClass->GetName();
}

void AMyOnlineBeaconHostObjectBase::PostInitProperties()
{
	if( ClientBeaconBlueprintClass )
	{
		ClientBeaconActorClass = ClientBeaconBlueprintClass;
	}
	BeaconTypeName = ClientBeaconActorClass->GetName();
	Super::PostInitProperties();
}

AOnlineBeaconHost* AMyOnlineBeaconHostObjectBase::GetOrSpawnBeaconHost()
{
	UOnlineBeaconWorldSubsystem* OnlineBeaconWorldSubsystem = GetWorld()->GetSubsystem<UOnlineBeaconWorldSubsystem>();
	check(OnlineBeaconWorldSubsystem )
	if( OnlineBeaconWorldSubsystem->BeaconHost == nullptr )
	{
		OnlineBeaconWorldSubsystem->BeaconHost = GetWorld()->SpawnActor<AOnlineBeaconHost>(AOnlineBeaconHost::StaticClass());
		if( OnlineBeaconWorldSubsystem->BeaconHost->InitHost() == false )
		{
			OnlineBeaconWorldSubsystem->BeaconHost->Destroy();
			OnlineBeaconWorldSubsystem->BeaconHost = nullptr;
		}
	}
	return OnlineBeaconWorldSubsystem->BeaconHost;
}

void AMyOnlineBeaconHostObjectBase::StartHost()
{
	Disconnect();

	AOnlineBeaconHost* BeaconHost = GetOrSpawnBeaconHost();
	if( BeaconHost )
	{
		BeaconHost->RegisterHost(this);
		BeaconHost->PauseBeaconRequests(false);
	}
	if( OnlineBeaconStateClass )
	{
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = this;
		State = GetWorld()->SpawnActor<AMyOnlineBeaconStateBase>(OnlineBeaconStateClass.Get(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnInfo);
		State->SetNetDriverName(GetNetDriverName());
	}
}

void AMyOnlineBeaconHostObjectBase::Disconnect()
{
	AOnlineBeaconHost* BeaconHost = GetOrSpawnBeaconHost();
	if( BeaconHost )
	{
		BeaconHost->UnregisterHost(GetBeaconType());
	}
}
