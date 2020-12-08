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
	system("mode con cols=100 lines=25 | title ����"); // �ܼ�â ũ�� �� ���� ����
	system("title DanceDance");
}

void Scene::setColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void Scene::ScreenClear() {

	system("cls");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void Scene::GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
