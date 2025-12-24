// Copyright 2023-2026 - MegaPunk Games Inc. - All Rights Reserved

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
