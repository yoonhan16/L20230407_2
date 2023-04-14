#include "Actor.h"
#include <iostream>
#include <windows.h>


using namespace std;                        // 메인함수 아니면 잘 안씀

AActor::AActor()
    : X(1), Y(1), Shape(' ')       // 초기값 설정 (언리얼엔진에선 필요없음)
{
}
//{
//    X = 1;
//    Y = 1;
//    Shape = ' ';
//}

AActor::AActor(int NewX, int NewY, char NewShape)
{
    X = NewX;
    Y = NewY;
    Shape = NewShape;

}

AActor::~AActor()
{

}

void AActor::Tick()
{

}

void AActor::Render()
{

        COORD Pos;
        Pos.X = X;
        Pos.Y = Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);


	cout << Shape << endl;
}
