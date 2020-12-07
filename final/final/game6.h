#ifndef GAME6_H
#define GAME6_H

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

//폰트색 변경을 위한 define
#define col GetStdHandle (STD_OUTPUT_HANDLE)
#define SetColor_Red SetConsoleTextAttribute (col, 0x000c );
#define SetColor_Blue SetConsoleTextAttribute (col, 0x0001 | 0x0008 );
#define SetColor_Green SetConsoleTextAttribute (col, 0x0002 );
#define SetColor_Yellow SetConsoleTextAttribute (col, 0x000e );
#define SetColor_White SetConsoleTextAttribute (col, 0x000f );

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void gotoxy(int x, int y);

class GameManager {
private:
	int level = 1;
	int life = 5;
public:
	int getLife();
	void increaseLife();
	void decreaseLife();
	// void resetLife();
	void setLife();
	// void printAnnounce();
	int getLevel();
	void levelUp();
};


class Arrow {
private:
	int x, y, type;
	bool state = true;
public:
	void setAttribute(int x, int y, int type);
	// void drawArrow();
	int getType();
	bool getState();
	void setState(bool state);
	void setXY(int x, int y);
	int getX();
	int getY();
};

class View {
public:
	static void printAnnounce(GameManager gm);
	static void drawArrow(Arrow ar);
};


class Game6 {
private:
	int sw_x[53] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 11, 12, 12, 13, 13, 14, 15, 15, 16, 17, 17, 18, 19, 19, 20, 20, 21, 21, 21, 22, 22, 22 };
	int sw_y[53] = { 10, 10,11,11,11,11,11,11,10,9,8,7,6,6,6,6,6,5,4,3,2,1,1,1,1,1,1,2,3,4,5,6,7,8,9,10,11,10,9,8,9,10,11,10,9,8,7,6,5,4,3,2,1 };
	int sw_type[53] = { 0, 1,2,4,1,3,2,1,4,4,3,2,1,4,2,4,3,2,4,1,1,3,4,3,2,2,3,2,4,1,2,3,4,2,1,1,2,4,2,1,3,3,2,2,4,1,2,3,1,4,2,1,2 };

	int flag_x[58] = { 17, 16,15,14,13,12,11,10,10,9,8,7,6,6,5,4,3,2,1,2,3,4,3,2,2,3,4,4,5,6,7,7,8,9,9,10,11,12,13,13,13,14,14,14,15,16,16,17,17,17,17,17,17,16,16,16,15,15 };
	int flag_y[58] = { 1, 1, 1, 1, 1,2,3,3,4,4,4,4,4,5,5,5,5,6,7,8,8,9,10,11,12,12,12,11,11,10,10,9,8,8,9,10,10,9,8,7,6,5,4,3,3,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int flag_type[58] = { 0,1,3,3,1,2,3,4,1,3,2,3,1,1,2,3,1,3,4,3,1,3,1,3,3,4,1,3,2,4,3,3,2,3,4,3,1,2,3,1,1,4,4,4,2,3,3,1,3,2,3,3,1,2,1,3,3,1 };

	// int* arr[2][3] = { {sw_x, sw_y, sw_type}, {flag_x,flag_y,flag_type} };

public:
	void playGame(GameManager gm, Arrow arrowArr[], int len);
	int game6();
};
#endif