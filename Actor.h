#pragma once

// �߻� Ŭ����, �������̽��� ����ٴ� ��
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape);
	virtual ~AActor();


	//virtual void Input();               // = 0 �� ��������� �����Լ�, ������ ��� �޾ƾ߸� ��.
	virtual void Tick();
	virtual void Render();

	virtual bool operator<(AActor& RHS)       // LHS , RHS (���� ������ ���ϴ� ���)
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
	// static �� ������ ó������ �޸𸮸� �Ҵ�����, Ŭ���� �ȿ� ������ Ŭ����::�Լ� �� �ٷ� ȣ�� ����, ������ ���� ó��
	// ������ ���� �� ����. ��, private ���� ���� �ʱ�ȭ ����� �� (����Ÿ�� Ŭ�����̸� :: �����̸�)
	// ���� = Ŭ���� ������ ��� ���� ��� �Ұ�

public:                                 // protected �� �ϸ� get set �� �������� �ؼ� �����ϰ� ������ϱ�...������ ��������
	int X;
	int Y;
	char Shape;
	int SortOrder = 1; // ���� ���� �� ���� �׸��� (�̰Ŵ� ������ ����)
	bool bIsCollision = false;

};

