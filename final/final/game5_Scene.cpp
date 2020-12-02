#pragma once
#define CRT_SECURE_NO_WARNINGS
//#include "MINIGAME.h"
#include "game5_Scene.h"
#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include <cmath>

//using namespace std;
//#pragma comment(lib,"winmm") 

void Scene::Console() {
	system("mode con cols=100 lines=25 | title 제목"); // 콘솔창 크기 및 제목 설정
	system("title DanceDance");
}

void Scene::setColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void Scene::ScreenInit() {

	//CONSOLE_CURSOR_INFO cci;
	// 커서 숨기기
	//cci.dwSize = 1;
	//cci.bVisible = FALSE;
	//SetConsoleCursorInfo(g_hScreen[0], &cci);
	//SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void Scene::ScreenFlipping() {
	//Sleep(10);
	//SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	//g_nScreenIndex = !g_nScreenIndex;
}

void Scene::ScreenClear() {
	//COORD Coor = { 0,0 };
	//DWORD dw;
	//FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
	system("cls");
}

void Scene::ScreenRelease() {
	//CloseHandle(g_hScreen[0]);
	//CloseHandle(g_hScreen[1]);
}

//커서의 위치를 x, y로 이동하는 함수
void Scene::GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
