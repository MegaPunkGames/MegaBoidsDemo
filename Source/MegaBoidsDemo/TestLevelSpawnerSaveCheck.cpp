// Copyright 2023-2025 - MegaPunk Games Inc. - All Rights Reserved


#include "TestLevelSpawnerSaveCheck.h"

#include "EngineUtils.h"
#include "MegaBoidsSpawner.h"
#include "UObject/ObjectSaveContext.h"

ATestLevelSpawnerSaveCheck::ATestLevelSpawnerSaveCheck()
{
	bIsEditorOnlyActor = true;
}

void ATestLevelSpawnerSaveCheck::PreSave(FObjectPreSaveContext SaveContext)
{
	Super::PreSave(SaveContext);

	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AMegaBoidsSpawner* Spawner = Cast<AMegaBoidsSpawner>(*It);

		if (IsValid(Spawner))
		{
			Spawner->EnableSpawnOnBeginPlay(false);
		}
	}
}

