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
}

void GameEngine::Init()
{
	World = new UWorld();
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
	KeyCode = _getch();
}

void GameEngine::Tick()
{
	World->Tick();
}

void GameEngine::Render()
{
	World->Render();
}
