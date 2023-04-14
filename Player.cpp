#include "Player.h"

APlayer::APlayer()
{
	Shape = 'P';
	X = 2;
	Y = 2;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
	:AActor(NewX, NewY, NewShape)
{
	SortOrder = 3;
}

APlayer::~APlayer()
{
}
