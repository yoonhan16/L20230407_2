#include "Wall.h"

AWall::AWall()
{
}

AWall::AWall(int NewX, int NewY, char NewShape)
	  :AActor(NewX, NewY, NewShape)
{

	//AActor::AActor(NewX, NewY, NewShape);
	//
	//X = NewX;
	//Y = NewY;
	//Shape = NewShape;
}

AWall::~AWall()
{
}
