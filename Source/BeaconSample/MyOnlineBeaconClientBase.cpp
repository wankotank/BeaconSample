// Fill out your copyright notice in the Description page of Project Settings.


#include "MyOnlineBeaconClientBase.h"
#include "OnlineSubsystemUtils.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "BeaconSample.h"


bool AMyOnlineBeaconClientBase::ConnectToBeaconHost(const FBlueprintSessionResult& InSessionSearchResult)
{
	const FOnlineSessionSearchResult& SearchResult = InSessionSearchResult.OnlineResult;
	// Make this stuff common?
	bool bSuccess = false;
	IOnlineSubsystem* OnlineSub = Online::GetSubsystem(GetWorld());
	if (OnlineSub == nullptr) { return bSuccess; }

	IOnlineSessionPtr SessionInt = OnlineSub->GetSessionInterface();
	if (SessionInt.IsValid() == false) { return bSuccess; }

	FString ConnectInfo;
	if (SessionInt->GetResolvedConnectString(SearchResult, NAME_BeaconPort, ConnectInfo))
	{
		FURL ConnectURL(NULL, *ConnectInfo, TRAVEL_Absolute);
		if (this->InitClient(ConnectURL) && SearchResult.Session.SessionInfo.IsValid())
		{
			//			DestSessionId = DesiredHost.Session.SessionInfo->GetSessionId().ToString();
			bSuccess = true;
		}
		else
		{
			UE_LOG(LogBeaconSample, Warning, TEXT("ConnectToBeaconHost: Failure to init client beacon with %s."), *ConnectURL.ToString());
		}
	}
	return bSuccess;
}

void AMyOnlineBeaconClientBase::Disconnect()
{
	DestroyBeacon();
}
