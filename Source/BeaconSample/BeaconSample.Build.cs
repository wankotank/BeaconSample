// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BeaconSample : ModuleRules
{
	public BeaconSample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OnlineSubsystem", "OnlineSubsystemUtils" });
	}
}
