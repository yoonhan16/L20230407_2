#include "Wall.h"

AWall::AWall()
{
}

AWall::AWall(int NewX, int NewY, char NewShape)
	  :AActor(NewX, NewY, NewShape)
{
	SortOrder = 2;                           //���߿� �� ���� �ٸ� ������ ���� �͵� �����ؼ� �� �����
	//AActor::AActor(NewX, NewY, NewShape);
	//
	//X = NewX;
	//Y = NewY;
	//Shape = NewShape;
}

AWall::~AWall()
{
}
