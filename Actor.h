#pragma once

// �߻� Ŭ����, �������̽��� ����ٴ� ��
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();


	virtual void Input();               // = 0 �� ��������� �����Լ�, ������ ��� �޾ƾ߸� ��.
	virtual void Tick();
	virtual void Render();

public:                                 // protected �� �ϸ� get set �� �������� �ؼ� �����ϰ� ������ϱ�...������ ��������
	int X;
	int Y;
	char Shape;



};

