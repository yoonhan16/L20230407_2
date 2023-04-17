#include <iostream>
#include "MyGameEngine.h"


// 이쁘게 하고 싶으면 sprite sheet 의 캐릭터를 잘라서 p 데이터에 넣기, 된다면 시간의 흐름에 따라 움직이는 캐릭터 구현

using namespace std;

int SDL_main(int argc, char* argv[])         //SDL2 가 있을때에만 써주는, cocos가 더 많이 쓰지만 코드로 다 쳐야 하니까 스킵, SDL은 심플하고 좋음
{
	GEngine->Init();
	GEngine->Run();

	delete GEngine;

	return 0;
}
