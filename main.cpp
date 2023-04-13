#include <iostream>
#include "World.h"
#include "Player.h"
#include "Goal.h"
#include "GameEngine.h"

using namespace std;

int main()
{

	//bool bIsRunning = true;
	//GameEngine
	//UWorld* World = new UWorld();
	//
	//Load
	//World->SpawnActor(new APlayer());
	//World->SpawnActor(new AGoal());

	GameEngine* Engine = new GameEngine();

	Engine->init();
	Engine->Run();



	return 0;
}