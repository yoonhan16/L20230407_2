#pragma once
#include <vector>

class AActor;                                //���漱��, ��� ���� �������� ���, ������

class UWorld
{
public:

	UWorld();
	virtual ~UWorld();                 

	void SpawnActor(AActor* NewActor);              // �����͸� �޾ƾ� ������ �ڽĵ��� �� ���´�, �׸��� protected �� �����ؾ� ��

	virtual void input();
	virtual void Tick();
	virtual void Render();

public:	

	std::vector<AActor*> Actors;
};

