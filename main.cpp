#include <iostream>
#include "MyGameEngine.h"


// �̻ڰ� �ϰ� ������ sprite sheet �� ĳ���͸� �߶� p �����Ϳ� �ֱ�, �ȴٸ� �ð��� �帧�� ���� �����̴� ĳ���� ����

using namespace std;

int SDL_main(int argc, char* argv[])         //SDL2 �� ���������� ���ִ�, cocos�� �� ���� ������ �ڵ�� �� �ľ� �ϴϱ� ��ŵ, SDL�� �����ϰ� ����
{
	GEngine->Init();
	GEngine->Run();

	delete GEngine;

	return 0;
}
