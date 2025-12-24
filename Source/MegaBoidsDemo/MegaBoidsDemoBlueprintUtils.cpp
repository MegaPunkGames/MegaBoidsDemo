// Copyright 2023-2026 - MegaPunk Games Inc. - All Rights Reserved


#include "MegaBoidsDemoBlueprintUtils.h"

#if WITH_EDITOR
#include "Editor.h"
#include "MegaBoidsEditorDebugSubsystem.h"
#endif

bool UMegaBoidsDemoBlueprintUtils::IsStatFPSEnabled()
{
#if WITH_ENGINE
    return GEngine != nullptr && GEngine->GameViewport != nullptr &&
           GEngine->GameViewport->IsStatEnabled("FPS");
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::DrawGroupLabels()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->DrawGroupLabels();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsDefaultDebugDrawEnabled()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsDefaultDebugDrawEnabled();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsDefaultBasicDrawEnabled()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsDefaultBasicDrawEnabled();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsDefaultSpacePartitionDrawEnabled()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsDefaultSpacePartitionDrawEnabled();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsDefaultSteeringForcesDrawEnabled()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsDefaultSteeringForcesDrawEnabled();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsDefaultAvoidanceForcesDrawEnabled()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsDefaultAvoidanceForcesDrawEnabled();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsDefaultMovementForcesDrawEnabled()
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsDefaultMovementForcesDrawEnabled();
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupDebugDrawOverriden(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupDebugDrawOverriden(GroupId);
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupDebugDrawEnabled(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupDebugDrawEnabled(GroupId);
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupBasicDrawEnabled(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupBasicDrawEnabled(GroupId);
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupSpacePartitionDrawEnabled(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupSpacePartitionDrawEnabled(GroupId);
#else
    return false;
#endif
}

int32 UMegaBoidsDemoBlueprintUtils::GetGroupSpacePartitionDrawLevel(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->GetGroupSpacePartitionDrawLevel(GroupId);
#else
    return 0;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupSteeringForcesDrawEnabled(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupSteeringForcesDrawEnabled(GroupId);
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupAvoidanceForcesDrawEnabled(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupAvoidanceForcesDrawEnabled(GroupId);
#else
    return false;
#endif
}

bool UMegaBoidsDemoBlueprintUtils::IsGroupMovementForcesDrawEnabled(const int32 GroupId)
{
#if WITH_EDITOR
    return GetDebugSubsystemSafe()->IsGroupMovementForcesDrawEnabled(GroupId);
#else
    return false;
#endif
}

#if WITH_EDITOR
UMegaBoidsEditorDebugSubsystem* UMegaBoidsDemoBlueprintUtils::GetDebugSubsystemSafe()
{
    return GEditor->GetEditorSubsystem<UMegaBoidsEditorDebugSubsystem>();
}
#endif
