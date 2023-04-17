#include "Actor.h"
#include <iostream>
#include <windows.h>
#include "MyGameEngine.h"

using namespace std;                        // 메인함수 아니면 잘 안씀

AActor::AActor()
    : X(1), Y(1), Shape(' ')       // 초기값 설정 (언리얼엔진에선 필요없음)
{
    R = 255;
    G = 255;
    B = 255;
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

//        COORD Pos;
//        Pos.X = X;
//        Pos.Y = Y;
//        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//
//
//        cout << Shape << endl;

    SDL_SetRenderDrawColor(GEngine->MyRenderer, R, G, B, 255);
    SDL_Rect MyRect = SDL_Rect{ (X - 1) * 30, (Y - 1) * 30, 30, 30 };        // x 위치 y 위치 가로 세로 , -1 하는 이유는 시작값이 1,1 이라서
    SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);

}
