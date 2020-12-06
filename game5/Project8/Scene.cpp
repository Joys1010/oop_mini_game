#pragma once
#define CRT_SECURE_NO_WARNINGS
#include "Scene.h"
#include<Windows.h>


void Scene::Console() { // �ܼ�â ũ�� �� ���� ����
	system("mode con cols=100 lines=25 | title DanceDance"); 
	system("title DanceDance");
}

void Scene::setColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void Scene::ScreenInit() {

}

void Scene::ScreenFlipping() {
	Sleep(10);
}

void Scene::ScreenClear() {
	system("cls");
}

void Scene::ScreenRelease() {

}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void Scene::GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
