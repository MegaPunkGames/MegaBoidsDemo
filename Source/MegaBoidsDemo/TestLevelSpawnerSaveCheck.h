// Copyright 2023-2025 - MegaPunk Games

#pragma once

#include "CoreMinimal.h"

#include "TestLevelSpawnerSaveCheck.generated.h"

UCLASS()
class MEGABOIDSDEMO_API ATestLevelSpawnerSaveCheck : public AActor
{
	GENERATED_BODY()

public:
	ATestLevelSpawnerSaveCheck();

	virtual void PreSave(FObjectPreSaveContext SaveContext) override;
};
