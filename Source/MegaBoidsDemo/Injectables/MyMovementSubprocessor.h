// Copyright 2023-2025 - MegaPunk Games Inc. - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "MegaBoidsMovementSubprocessor.h"

#include "MyMovementSubprocessor.generated.h"

struct FMegaBoidsMovementExecutionContext;
struct FMegaBoidsAvoidanceFragment;
struct FMegaBoidsSteeringFragment;
struct FMegaBoidsDrivingFragment;
struct FMegaBoidsFragment;

UCLASS(BlueprintType, meta = (DisplayName = "My Custom Movement"))
class UMyMovementConfig : public UMegaBoidsMovementSubprocessorConfig
{
	GENERATED_BODY()
};

class UMyMovementSubprocessorDefinition
{
public:
	static void SetupQuery(FMassEntityQuery& Query) { }
	static void SetupTrait(FMegaBoidsBuildContext& BuildContext, const UMegaBoidsMovementSubprocessorConfig* Config) { }
	static void InitializeEntity(const FMegaBoidsMovementInitializationContext& Context) { }

	static void ApplyMovement(const FMegaBoidsMovementExecutionContext& Context, const FMegaBoidsMovementData& BoidFragment, const FVector& PropulsionForce, const FVector& SteeringForce, const FVector& AvoidanceForce, float DeltaTime);
};

UCLASS()
class UMyMovementSubprocessorDeclaration : public UMegaBoidsMovementSubprocessorDeclaration
{
	GENERATED_BODY()
	MEGABOIDS_GENERATE_MOVEMENT_SUBPROCESSOR_BODY(UMyMovementConfig, UMyMovementSubprocessorDefinition)
};

