#include "Player.h"
#include "MyGameEngine.h"
#include "World.h"
APlayer::APlayer()
{
	Shape = 'P';
	X = 2;
	Y = 2;
	bIsCollision = false;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
	:AActor(NewX, NewY, NewShape)
{
	SortOrder = 3;
}

void APlayer::Tick()
{
	switch (GEngine->KeyCode)
	{
		//if (X == 1 && X == 10 && Y == 1 && Y == 10)
		//{
		//	return;
		//}

	case 'w':
		if (!GEngine->GetWorld()->CheckCollision(X, Y - 1))
		{
			Y--;
		}
		break;
	case 's':
		if (!GEngine->GetWorld()->CheckCollision(X, Y + 1))
		{
			Y++;
		}
		break;
	case 'a':
		if (!GEngine->GetWorld()->CheckCollision(X - 1, Y))
		{
			X--;
		}
		break;
	case 'd':
		if (!GEngine->GetWorld()->CheckCollision(X + 1, Y))
		{
			X++;
		}
		break;
	case 'q':
		GEngine->Stop();
		break;
	}
}

APlayer::~APlayer()
{
}
