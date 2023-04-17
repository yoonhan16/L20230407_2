#define _CRT_SECURE_NO_WARNINGS          //fopen �Լ� ��ü�� ���װ� ����, �̰ɷ� ���ݵ� ����, ���� �Ƹ��� �ϴ� ������ (iostream �� �� ����), �ٸ��� �Ⱦ��� ���⿡�� ����

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
	SDL_Quit();                                 // C style �ڵ�, �̴ְ� ţ ���̿� ������ ��

}

void GameEngine::Init()
{
	World = new UWorld();

	SDL_Init(SDL_INIT_EVERYTHING);

	MyWindow = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_VULKAN);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_TARGETTEXTURE
		| SDL_RENDERER_ACCELERATED);           // �ڿ� �ִ� 2���� 3D �Ҷ� �ʿ�, ������ 0? �־ ���ư�


}

void GameEngine::Load(std::string Filename)                        //UE ��Ÿ���� LoadLevel
{
	FILE* file;          //������ ó�� ���� ������ �д� ����        getc = �ֿܼ��� �б� fgetc = ���Ͽ��� �б�
	char c;
	file = fopen(Filename.c_str(), "r");                         //c_str() = const string �� �޾ƿ��� �Լ�

	int PositionX = 1;
	int PositionY = 1;

	while ((c = fgetc(file)) != EOF)
	{
		if (c == '*')
		{
			GetWorld()->SpawnActor(new AWall(PositionX, PositionY));
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("��");
		}
		else if (c == ' ')
		{
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("�ٴ�");
		}
		else if (c == 'P')
		{
			GetWorld()->SpawnActor(new APlayer(PositionX, PositionY));
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("�÷��̾�");
		}
		else if (c == 'G')
		{
			GetWorld()->SpawnActor(new AGoal(PositionX, PositionY));
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("��ǥ");
		}
		else if (c == 'M')
		{
			GetWorld()->SpawnActor(new AMonster(PositionX, PositionY));
			GetWorld()->SpawnActor(new AFloor(PositionX, PositionY));
			//printf("����");
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
