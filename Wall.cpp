#include "Wall.h"

AWall::AWall()
{
	bIsCollision = true;
}

AWall::AWall(int NewX, int NewY, char NewShape)
	  :AActor(NewX, NewY, NewShape)
{
	SortOrder = 2;                           //나중에 할 때는 다른 변수가 들어올 것도 감안해서 좀 띄워둠
	//AActor::AActor(NewX, NewY, NewShape);
	//
	//X = NewX;
	//Y = NewY;
	//Shape = NewShape;

	bIsCollision = true;

}

AWall::~AWall()
{
}

