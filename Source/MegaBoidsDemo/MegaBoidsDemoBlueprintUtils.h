// Copyright 2023-2026 - MegaPunk Games Inc. - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MegaBoidsDemoBlueprintUtils.generated.h"

class UMegaBoidsEditorDebugSubsystem;
/**
 * 
 */
UCLASS(meta=(ScriptName = "MegaBoids"))
class MEGABOIDSDEMO_API UMegaBoidsDemoBlueprintUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, DisplayName="Is StatFPS Enabled", Category="MegaBoids|Utils")
    static bool IsStatFPSEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool DrawGroupLabels();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsDefaultDebugDrawEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsDefaultBasicDrawEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsDefaultSpacePartitionDrawEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsDefaultSteeringForcesDrawEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsDefaultAvoidanceForcesDrawEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsDefaultMovementForcesDrawEnabled();

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupDebugDrawOverriden(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupDebugDrawEnabled(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupBasicDrawEnabled(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupSpacePartitionDrawEnabled(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static int32 GetGroupSpacePartitionDrawLevel(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupSteeringForcesDrawEnabled(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupAvoidanceForcesDrawEnabled(const int32 GroupId);

    UFUNCTION(BlueprintPure, Category="MegaBoids|Utils", meta=(DevelopmentOnly))
    static bool IsGroupMovementForcesDrawEnabled(const int32 GroupId);

private:
#if WITH_EDITOR
    static UMegaBoidsEditorDebugSubsystem* GetDebugSubsystemSafe();
#endif
};
