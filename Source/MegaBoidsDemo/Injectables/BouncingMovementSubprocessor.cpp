// Copyright 2023-2026 - MegaPunk Games Inc. - All Rights Reserved

#include "BouncingMovementSubprocessor.h"

#include "MegaBoidsContext.h"
#include "Commands/MegaBoidsUpdateShaderCustomDataCommand.h"
#include "Fragments/MegaBoidsCommonFragments.h"

void UBouncingMovementSubprocessorDefinition::SetupQuery(FMassEntityQuery& Query)
{
    Query.AddRequirement<FBouncingMovementFragment>(EMassFragmentAccess::ReadWrite);
    Query.AddRequirement<FBouncingAnimationFragment>(EMassFragmentAccess::ReadWrite, EMassFragmentPresence::Optional);
    Query.AddConstSharedRequirement<FBouncingMovementSharedFragment>();
}

void UBouncingMovementSubprocessorDefinition::SetupTrait(FMegaBoidsMovementBuildContext& BuildContext, const UMegaBoidsMovementSubprocessorConfig* Config)
{
    const UBouncingMovementConfig* BounceConfig = Cast<const UBouncingMovementConfig>(Config);

    BuildContext.AddFragment<FBouncingMovementFragment>();

    FBouncingMovementSharedFragment& BounceSharedFragment = BuildContext.AddConstSharedFragment_GetRef<FBouncingMovementSharedFragment>();
    BounceSharedFragment.BounceStrength = BounceConfig->BounceStrength;
    BounceSharedFragment.Gravity = BounceConfig->Gravity;
    BounceSharedFragment.BounceAnimDelay = BounceConfig->BounceAnimDelay;
}

void UBouncingMovementSubprocessorDefinition::InitializeEntity(const FMegaBoidsMovementInitializationContext& Context)
{
    const FBouncingMovementSharedFragment& BounceSharedFragment = Context.GetConstSharedFragment<FBouncingMovementSharedFragment>();
    FBouncingMovementFragment& BounceFragment = Context.GetFragment<FBouncingMovementFragment>();
    FMegaBoidsTransformFragment& TransformFragment = Context.GetFragment<FMegaBoidsTransformFragment>();

    BounceFragment.VerticalVelocity = FMath::RandRange(-BounceSharedFragment.BounceStrength, BounceSharedFragment.BounceStrength); // Start with a random velocity.

    FVector SpawnLocation = TransformFragment.GetMutableTransform().GetLocation();
    SpawnLocation.Z = (FMath::Square(BounceFragment.VerticalVelocity) - FMath::Square(BounceSharedFragment.BounceStrength)) / (-2 * BounceSharedFragment.Gravity); // Compute Z height from initialized random velocity
    TransformFragment.GetMutableTransform().SetTranslation(SpawnLocation);

    // Compute animation start time from initialized velocity. Animation is 1 second long...
    FBouncingAnimationFragment* AnimFragment = Context.GetFragmentPtr<FBouncingAnimationFragment>();
    if (AnimFragment != nullptr)
    {
        AnimFragment->AnimStartTime = Context.GetWorld()->GetTimeSeconds() - FMath::GetRangePct(-BounceSharedFragment.BounceStrength, BounceSharedFragment.BounceStrength, BounceFragment.VerticalVelocity);
    }
}

void UBouncingMovementSubprocessorDefinition::ApplyMovement(const FMegaBoidsMovementExecutionContext& Context, const FMegaBoidsMovementData& MovementData, const FVector& DrivingForce, const FVector& SteeringForce, const FVector& AvoidanceForce)
{
    const FBouncingMovementSharedFragment& BounceSharedFragment = Context.GetConstSharedFragment<FBouncingMovementSharedFragment>();
    FBouncingMovementFragment& BounceFragment = Context.GetMutableFragment<FBouncingMovementFragment>();

    if (BounceFragment.ImpulseDelay > 0)
    {
        BounceFragment.ImpulseDelay -= Context.GetDeltaTimeSeconds();
    }
    else
    {
        double currentBounceVelocity = BounceFragment.VerticalVelocity;

        // Apply gravity acceleration
        BounceFragment.VerticalVelocity -= BounceSharedFragment.Gravity * Context.GetDeltaTimeSeconds();

        // Everything else is just kinetic movement.
        const FVector AccelerationForce = DrivingForce + SteeringForce + AvoidanceForce; // Fixed mass for the sake of the demo
        FVector UpdateVelocity = MovementData.GetVelocity() + AccelerationForce * Context.GetDeltaTimeSeconds();
        UpdateVelocity.Z = currentBounceVelocity;

        FTransform& BoidTransform = MovementData.GetMutableTransform();
        FVector BoidPosition = BoidTransform.GetLocation();
        BoidPosition += UpdateVelocity * Context.GetDeltaTimeSeconds();

        // For the sake of the demo, we assume a flat ground. Therefore, our entity hits the ground when velocity is under the impulse strength.
        if (BounceFragment.VerticalVelocity <= -BounceSharedFragment.BounceStrength)
        {
            // Clamp to floor
            BoidPosition.Z = 0;

            BounceFragment.ImpulseDelay = BounceSharedFragment.BounceAnimDelay; // Setup animation delay
            BounceFragment.VerticalVelocity = BounceSharedFragment.BounceStrength; // Apply bounce. Note this will be applied after animation delay expires

            // Start animation by setting up shader
            FBouncingAnimationFragment& AnimFragment = Context.GetMutableFragment<FBouncingAnimationFragment>();
            AnimFragment.AnimStartTime = Context.GetWorld()->GetTimeSeconds();

            Context.Defer().PushCommand<FMegaBoidsUpdateShaderCustomDataCommand>(Context.GetEntity());
        }

        BoidTransform.SetLocation(BoidPosition);
    }
}
