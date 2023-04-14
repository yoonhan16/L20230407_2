#include "MyGameEngine.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "Monster.h"
#include "Goal.h"
#include "World.h"

MyGameEngine* MyGameEngine::Instance = nullptr;

MyGameEngine::MyGameEngine()
{

}

MyGameEngine::~MyGameEngine()
{

}

void MyGameEngine::Init()
{
	GameEngine::Init();
	//__super::init();

	//Map_Load
	Load("level1.dat");

}

