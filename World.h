#pragma once
#include <vector>

class AActor;                                //���漱��, ��� ���� �������� ���, ������

class UWorld
{
public:

	UWorld();
	virtual ~UWorld();                 

	void SpawnActor(AActor* NewActor);              // �����͸� �޾ƾ� ������ �ڽĵ��� �� ���´�, �׸��� protected �� �����ؾ� ��

	virtual void Tick();
	virtual void Render();

	void Sort();

	//������ physics ���� �����ϴ� �׸�
	bool CheckCollision(int X, int Y);

public:	

	std::vector<AActor*> Actors;
};

