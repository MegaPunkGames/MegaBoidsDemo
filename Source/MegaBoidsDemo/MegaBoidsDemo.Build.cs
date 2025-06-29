// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class MegaBoidsDemo : ModuleRules
	{
		public MegaBoidsDemo(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"Engine",
					"StructUtils",
					"DeveloperSettings",
					"MassEntity",
					"MassSpawner",
				}
			);

			if (Target.bBuildEditor)
			{
				PrivateDependencyModuleNames.AddRange(
					new string[] {
						"UnrealEd",
						"MegaCompat",
						"MegaBoids",
						"MegaBoidsEditor"
					}
				);
			}
		}
	}
}