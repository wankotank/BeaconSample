// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHostObject.h"
#include "MyOnlineBeaconClientBase.h"
#include "MyOnlineBeaconStateBase.h"
#include "MyOnlineBeaconHostObjectBase.generated.h"

/**
 * 
 */
UCLASS()
class BEACONSAMPLE_API AMyOnlineBeaconHostObjectBase : public AOnlineBeaconHostObject
{
	GENERATED_UCLASS_BODY()

private:
	AOnlineBeaconHost* GetOrSpawnBeaconHost();

public:

	UFUNCTION(BlueprintCallable)
	void StartHost();

	UFUNCTION(BlueprintCallable)
	void Disconnect();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMyOnlineBeaconClientBase>	ClientBeaconBlueprintClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMyOnlineBeaconStateBase>	OnlineBeaconStateClass;

	UPROPERTY(Transient)
	AMyOnlineBeaconStateBase* State;

	virtual void PostInitProperties() override;
};
