#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor != nullptr)
	{
		Actors.push_back(NewActor);
	}
}
