// Copyright 2023-2025 - MegaPunk Games

using UnrealBuildTool;

public class MegaBoidsDemoEditorTarget : TargetRules
{
    public MegaBoidsDemoEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "MegaBoidsDemo" } );
    }
}
