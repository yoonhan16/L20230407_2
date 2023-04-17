#include "Player.h"
#include "MyGameEngine.h"
#include "World.h"
APlayer::APlayer()
{
	Shape = 'P';
	X = 2;
	Y = 2;
	bIsCollision = false;

	R = 0;
	G = 0;
	B = 255;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
	:AActor(NewX, NewY, NewShape)
{
	SortOrder = 3;
	R = 0;
	G = 0;
	B = 255;
}

void APlayer::Tick()
{
	if (GEngine->MyEvent.type == SDL_KEYDOWN)                //한번만 입력하게 해줌
	{
		return;
	}


	switch (GEngine->MyEvent.key.keysym.sym)
	{
		//if (X == 1 && X == 10 && Y == 1 && Y == 10)
		//{
		//	return;
		//}

	case SDLK_w:
	case SDLK_UP:
		if (!GEngine->GetWorld()->CheckCollision(X, Y - 1))
		{
			Y--;
		}
		break;
	case SDLK_s:
	case SDLK_DOWN:
		if (!GEngine->GetWorld()->CheckCollision(X, Y + 1))
		{
			Y++;
		}
		break;
	case SDLK_a:
	case SDLK_LEFT:
		if (!GEngine->GetWorld()->CheckCollision(X - 1, Y))
		{
			X--;
		}
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		if (!GEngine->GetWorld()->CheckCollision(X + 1, Y))
		{
			X++;
		}
		break;
	case SDLK_ESCAPE:
	case SDLK_q:
		GEngine->Stop();
		break;
	}
}

APlayer::~APlayer()
{
}
