#include "Monster.h"
#include "MyGameEngine.h"


AMonster::AMonster()
{

}

AMonster::AMonster(int NewX, int NewY, char NewShape)
	:AActor(NewX, NewY, NewShape)
{
	SortOrder = 4;

	R = 255;
	G = 255;
	B = 0;

}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	if (GEngine->MyEvent.type == SDL_KEYDOWN)
	{
		return;
	}

}
