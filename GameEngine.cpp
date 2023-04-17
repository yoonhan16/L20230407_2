#define _CRT_SECURE_NO_WARNINGS          //fopen 함수 자체에 버그가 있음, 이걸로 공격도 가능, 뜻은 아몰랑 일단 쓰고볼랭 (iostream 에 들어가 있음), 다른데 안쓰고 여기에만 존재

#include "GameEngine.h"
#include "World.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"

#include <algorithm>
#include <iostream>
#include <conio.h>



GameEngine::GameEngine()
{
	bIsRunning = true;
	World = nullptr;
	KeyCode = 0;
}

GameEngine::~GameEngine()
{
	if (World != nullptr)
	{
		delete World;
		World = nullptr;
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();                                 // C style 코딩, 이닛과 큇 사이에 뭔가를 함

}

void GameEngine::Init()
{
	World = new UWorld();

	SDL_Init(SDL_INIT_EVERYTHING);

	MyWindow = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_VULKAN);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_TARGETTEXTURE
		| SDL_RENDERER_ACCELERATED);           // 뒤에 있는 2개는 3D 할때 필요, 지금은 0? 넣어도 돌아감


}

void GameEngine::Load(std::string Filename)                        //UE 스타일은 LoadLevel
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
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
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
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("플레이어");
		}
		else if (c == 'G')
		{
			GetWorld()->SpawnActor(new AGoal(PositionX, PositionY));
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("목표");
		}
		else if (c == 'M')
		{
			GetWorld()->SpawnActor(new AMonster(PositionX, PositionY));
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("몬스터");
		}

		if (c == '\n')
		{
			++PositionY;
			PositionX = 0;
		}
		//printf("%c", c);
		++PositionX;
	}


	fclose(file);

	GetWorld()->Sort();

}

void GameEngine::Run()
{
	while (bIsRunning) //Frame
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
	//KeyCode = _getch();
	SDL_PollEvent(&MyEvent);
}

void GameEngine::Tick()
{
	World->Tick();
}

void GameEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);

	World->Render();

	SDL_RenderPresent(MyRenderer);
}
