// Copyright 2023-2026 - MegaPunk Games Inc. - All Rights Reserved


#include "MyMovementSubprocessor.h"

void UMyMovementSubprocessorDefinition::ApplyMovement(const FMegaBoidsMovementExecutionContext& Context, const FMegaBoidsMovementData& BoidFragment, const FVector& PropulsionForce, const FVector& SteeringForce, const FVector& AvoidanceForce)
{
    // Just use driving force (ignore steering), this is just a proof of concept. Check BouncingBallMovementSubprocessorDefinition for a better example.
    if (!PropulsionForce.IsNearlyZero())
    {
        FTransform& BoidTransform = BoidFragment.GetMutableTransform();
        const FVector BoidPosition = BoidTransform.GetLocation();
        const FQuat BoidRotation = BoidTransform.GetRotation();
        const FVector MovementDirection = PropulsionForce.GetSafeNormal();
        const FVector NewUpVector = MovementDirection.Cross(BoidRotation.GetRightVector()).GetSafeNormal();
        const FVector NewRightVector = NewUpVector.Cross(MovementDirection).GetSafeNormal();
        const FQuat UpdatedRotation = FRotationMatrix::MakeFromYZ(NewRightVector, NewUpVector).ToQuat();

        BoidTransform.SetLocation(BoidPosition + PropulsionForce * Context.GetDeltaTimeSeconds());
        BoidTransform.SetRotation(UpdatedRotation);
    }
}
