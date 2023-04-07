#pragma once

// 추상 클래스, 인터페이스를 만든다는 뜻
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();


	virtual void Input();               // = 0 이 붙으면순수 가상함수, 무조건 상속 받아야만 함.
	virtual void Tick();
	virtual void Render();

public:                                 // protected 로 하면 get set 다 만들어줘야 해서 복잡하고 길어지니까...순전히 수업용임
	int X;
	int Y;
	char Shape;



};

