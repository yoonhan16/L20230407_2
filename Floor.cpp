#include "Floor.h"

AFloor::AFloor()
{
}

AFloor::AFloor(int NewX, int NewY, char NewShape)
   	:AActor(NewX, NewY, NewShape)
{
    SortOrder = 1;
}

AFloor::~AFloor()
{
}
