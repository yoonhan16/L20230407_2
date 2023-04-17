#pragma once
#include "Actor.h"
#include <string>
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape = 'M');
	virtual~AMonster();

	virtual void Tick() override;


};

