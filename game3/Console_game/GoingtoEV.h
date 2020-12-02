#ifndef GOINGTOEV_H
#define GOINGTOEV_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <mmsystem.h>
#include <random>
#pragma comment(lib,"winmm.lib")

using namespace std;

#define PLAYER_BOTTOM_Y 12
#define OBSTACLE_BOTTOM_Y 20
#define OBSTACLE_BOTTOM_X 45

class Game3
{
private:
	int life;
	int gravity;
	bool isJumping;
	bool isBottom;
	int playerY;
	int obstacleX;

public:
	Game3();
	void SetConsoleView();
	void GotoXY(int x, int y);
	int GetKeyDown();
	void DrawPlayer(int playerY);
	void DrawObstacle(int obstacleX, int prob);
	void DrawGameOver();
	bool isCollision(const int obstacleX, const int playerY, const int life);
	int display();
};


#endif