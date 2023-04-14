#pragma once

// 추상 클래스, 인터페이스를 만든다는 뜻
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();


	//virtual void Input();               // = 0 이 붙으면순수 가상함수, 무조건 상속 받아야만 함.
	virtual void Tick();
	virtual void Render();

	virtual bool operator<(AActor& RHS)       // LHS , RHS (왼쪽 오른쪽 비교하는 언어)
	{
		return (this->SortOrder) < (RHS.SortOrder);
	}

	virtual bool operator>(AActor& RHS)       
	{
		return (this->SortOrder) > (RHS.SortOrder);
	}

	static inline bool Compare(const AActor* LHS, const AActor* RHS)
	{
		return (LHS->SortOrder) < (RHS->SortOrder);
	}
	// static 이 붙으면 처음부터 메모리를 할당해줌, 클래스 안에 있으면 클래스::함수 로 바로 호출 가능, 일종의 예외 처리
	// 변수도 붙일 수 있음. 단, private 에서 값을 초기화 해줘야 함 (변수타입 클래스이름 :: 변수이름)
	// 단점 = 클래스 내부의 멤버 변수 사용 불가

public:                                 // protected 로 하면 get set 다 만들어줘야 해서 복잡하고 길어지니까...순전히 수업용임
	int X;
	int Y;
	char Shape;
	int SortOrder = 1; // 숫자 작은 걸 먼저 그린다 (이거는 본인이 설정)
	bool bIsCollision = false;

};

