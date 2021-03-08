// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OnlineBeaconHost.h"
#include "OnlineBeaconWorldSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BEACONSAMPLE_API UOnlineBeaconWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY(Transient)
	AOnlineBeaconHost* BeaconHost;
};
