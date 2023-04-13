#include "Goal.h"

AGoal::AGoal()
{

	Shape = 'G';
	X = 9;
	Y = 9;

}

AGoal::AGoal(int NewX, int NewY, char NewShape)
	:AActor(NewX, NewY, NewShape)
{
}

AGoal::~AGoal()
{
}
