// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "MyOnlineBeaconStateBase.generated.h"

/**
 * 
 */
UCLASS(notplaceable, BlueprintType, Blueprintable)
class BEACONSAMPLE_API AMyOnlineBeaconStateBase : public AInfo
{
	GENERATED_UCLASS_BODY()
public:	
	bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const override;
};
