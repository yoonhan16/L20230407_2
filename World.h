#pragma once
#include <vector>

class AActor;                                //���漱��, ��� ���� �������� ���, ������

class UWorld
{
public:

	UWorld();
	virtual ~UWorld();

	std::vector<AActor*> Actors;                 

	void SpawnActor(AActor* NewActor);              // �����͸� �޾ƾ� ������ �ڽĵ��� �� ���´�, �׸��� protected �� �����ؾ� ��



};

