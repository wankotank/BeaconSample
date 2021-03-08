// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconClient.h"
#include "FindSessionsCallbackProxy.h"
#include "MyOnlineBeaconClientBase.generated.h"

/**
 *
 */
UCLASS()
class BEACONSAMPLE_API AMyOnlineBeaconClientBase : public AOnlineBeaconClient
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	bool ConnectToBeaconHost(const FBlueprintSessionResult& InSessionSearchResult);

	UFUNCTION(BlueprintCallable)
	void Disconnect();

};
