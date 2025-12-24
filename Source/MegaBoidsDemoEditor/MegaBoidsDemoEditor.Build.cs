// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
    public class MegaBoidsDemoEditor : ModuleRules
    {
        public MegaBoidsDemoEditor(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicDependencyModuleNames.AddRange(
                new string[] {
                    "MegaBoidsDemo",
                    "MegaBoidsEditor"
                }
            );
        }
    }
}