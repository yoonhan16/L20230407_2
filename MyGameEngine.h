#pragma once
#include "GameEngine.h"
class MyGameEngine : public GameEngine
{
public:
	MyGameEngine();
	virtual ~MyGameEngine();

	virtual void Init() override;

};