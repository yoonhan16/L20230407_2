#define _CRT_SECURE_NO_WARNINGS          //fopen 함수 자체에 버그가 있음, 이걸로 공격도 가능, 뜻은 아몰랑 일단 쓰고볼랭 (iostream 에 들어가 있음), 다른데 안쓰고 여기에만 존재

#include "GameEngine.h"
#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"

#include <iostream>

GameEngine::GameEngine()
{
	bIsRunning = true;
	World = nullptr;
}

GameEngine::~GameEngine()
{
	if (World != nullptr)
	{
		delete World;
		World = nullptr;
	}
}

void GameEngine::init()
{
	World = new UWorld();
}

void GameEngine::Load(std::string Filename)
{
	FILE* file;          //파일의 처음 시작 지점을 읽는 문장        getc = 콘솔에서 읽기 fgetc = 파일에서 읽기
	char c;
	file = fopen(Filename.c_str(), "r");                         //c_str() = const string 을 받아오는 함수

	int PositionX = 1;
	int PositionY = 1;

	while ((c = fgetc(file)) != EOF)
	{
		if (c == '*')
		{
			GetWorld()->SpawnActor(new AWall(PositionX, PositionY));
			//printf("벽");
		}
		else if (c == ' ')
		{
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("바닥");
		}
		else if (c == 'P')
		{
			GetWorld()->SpawnActor(new APlayer(PositionX, PositionY));
			printf("플레이어");
		}
		else if (c == 'G')
		{
			GetWorld()->SpawnActor(new AGoal(PositionX, PositionY));
			printf("목표");
		}
		else if (c == 'M')
		{
			GetWorld()->SpawnActor(new AMonster(PositionX, PositionY));
			printf("몬스터");
		}

		if (c == '\n')
		{
			++PositionY;
			PositionX = 1;
			printf("줄바꿈");
		}
		printf("%c", c);
		++PositionX;
	}


	fclose(file);
}

void GameEngine::Run()
{
	while (bIsRunning = true) //Frame
	{
		//system ("cls");
		input();
		Tick();
		Render();
	}
}

void GameEngine::Stop()
{
	bIsRunning = false;
}

void GameEngine::input()
{
	World->input();
}

void GameEngine::Tick()
{
	World->Tick();
}

void GameEngine::Render()
{
	World->Render();
}
