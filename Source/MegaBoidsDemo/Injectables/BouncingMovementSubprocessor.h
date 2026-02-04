// Copyright 2023-2026 - MegaPunk Games Inc. - All Rights Reserved

#pragma once

#include "MegaBoidsMovementSubprocessor.h"
#include "Fragments/MegaBoidsISMCustomDataFragment.h"
#include "MegaCompatTypes.h"

#include "BouncingMovementSubprocessor.generated.h"

USTRUCT()
struct FBouncingMovementFragment : public FMassFragment
{
public:
    GENERATED_BODY()

    // Will be in the range [-FBouncingMovementSharedFragment::BounceStrength, FBouncingMovementSharedFragment::BounceStrength] at runtime and used to move the ball vertically.
    float VerticalVelocity = 0;

    // Delay remaining between animation start and impulse being applied
    float ImpulseDelay = 0;	
};

USTRUCT()
struct FBouncingAnimationFragment : public FMegaBoidsISMCustomDataFragment
{
public:
    GENERATED_BODY()

    float AnimStartTime = 0;
};

USTRUCT()
struct FBouncingMovementSharedFragment : public FMegaCompatConstSharedFragment
{
public:
    GENERATED_BODY()

    float BounceStrength = 400;		// Strength of the impulse added when bouncing on a surface/ground
    float Gravity = 980;			// Gravity applied to the ball, in cm/sec
    float BounceAnimDelay = 0;		// Delay between anim start and bounce impulse
    
    friend FORCEINLINE uint32 GetTypeHash(const FBouncingMovementSharedFragment& SharedFragment)
    {
        const uint32 BaseCRC = FCrc::StrCrc32(*StaticStruct()->GetName());

        uint32 dataHash = HashCombineFast(GetTypeHash(SharedFragment.BounceStrength), GetTypeHash(SharedFragment.Gravity));

        return HashCombineFast(BaseCRC, dataHash);
    }
};

UCLASS(BlueprintType, meta = (DisplayName = "Bouncing Ball"))
class UBouncingMovementConfig : public UMegaBoidsMovementSubprocessorConfig
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ClampMin = 0, UIMin = 0, Tooltip="Strength at which the ball will bounce when it hits the floor."))
    float BounceStrength = 400;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ClampMin = 0, UIMin = 0, Tooltip="Gravity strength."))
    float Gravity = 980;			// Gravity acceleration applied to the ball, in cm/sec

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ClampMin = 0, UIMin = 0, Tooltip="Delay between anim start and bounce impulse."))
    float BounceAnimDelay = 0.5;
};

// Note that this is an example that could also be done with a driver and kinetic movement that adds an impulse when we hit the ground.
class UBouncingMovementSubprocessorDefinition
{
public:
    static void SetupQuery(FMassEntityQuery& Query);
    static void SetupTrait(FMegaBoidsMovementBuildContext& BuildContext, const UMegaBoidsMovementSubprocessorConfig* Config);
    static void InitializeEntity(const FMegaBoidsMovementInitializationContext& Context);

    static void ApplyMovement(const FMegaBoidsMovementExecutionContext& Context, const FMegaBoidsMovementData& MovementData, const FVector& DrivingForce, const FVector& SteeringForce, const FVector& AvoidanceForce);
};

UCLASS()
class UBouncingMovementSubprocessorDeclaration: public UMegaBoidsMovementSubprocessorDeclaration
{
    GENERATED_BODY()
    MEGABOIDS_GENERATE_MOVEMENT_SUBPROCESSOR_BODY(UBouncingMovementConfig, UBouncingMovementSubprocessorDefinition)
};
