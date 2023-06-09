#pragma once
#include <vector>

class AActor;                                //전방선언, 어딘가 쓸때 가져가서 써라, 포인터

class UWorld
{
public:

	UWorld();
	virtual ~UWorld();                 

	void SpawnActor(AActor* NewActor);              // 포인터를 달아야 액터의 자식들이 다 들어온다, 그리고 protected 로 구현해야 함

	virtual void Tick();
	virtual void Render();

	void Sort();

	//원래는 physics 에서 수행하는 항목
	bool CheckCollision(int X, int Y);

public:	

	std::vector<AActor*> Actors;
};

