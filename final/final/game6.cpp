#include "game6.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;



void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int GameManager::getLife() {
	return life;
}
void GameManager::decreaseLife() {
	life--;
}
void GameManager::increaseLife() {
	life++;
}
void GameManager::setLife() {
	life = 0;
}
int GameManager::getLevel() {
	return level;
}
void GameManager::levelUp() {
	level++;
}



void Arrow::setAttribute(int x, int y, int type) {
	this->x = x;
	this->y = y;
	this->type = type;
}
int Arrow::getType() {
	return type;
}
bool Arrow::getState() {
	return state;
}
void Arrow::setState(bool state) {
	this->state = state;	
}
void Arrow::setXY(int x, int y) { // for 커서 XY 설정
	this->x = x;
	this->y = y;
}
int Arrow::getX() {
	return x;
}
int Arrow::getY() {
	return y;
}


void View::printAnnounce(GameManager gm) {
	gotoxy(3, 2);
	SetColor_Red;
	cout << "▲ UP  ";
	SetColor_Yellow;
	cout << "▼ DOWN  ";
	SetColor_Green;
	cout << "◀ LEFT  ";
	SetColor_Blue;
	cout << "▶ RIGHT";
	SetColor_White;
	gotoxy(3, 3);
	int level = gm.getLevel();
	cout << "LEVEL : " << gm.getLevel() << " / LIFE : " << gm.getLife();
}

void View::drawArrow(Arrow ar) {
	gotoxy(ar.getX() *2 + 20, ar.getY() + 5);
	switch (ar.getType()) {
	case 0: //커서
		SetColor_White;
		cout << "◎";
		break;
	case 1: //up
		SetColor_Red;
		cout << "▲";
		SetColor_White;
		break;
	case 2: //down
		SetColor_Yellow;
		cout << "▼";
		SetColor_White;
		break;
	case 3: //left 
		SetColor_Green;
		cout << "◀";
		SetColor_White;
		break;
	case 4: //right
		SetColor_Blue;
		cout << "▶";
		SetColor_White;
		break;
	}
}

void Game6::playGame(GameManager gm, Arrow arrowArr[], int len) {
	char c;
	int key = 0;
	while (1) {
		if (kbhit()) {
			int tmp = 1; //지금 몇 번째 화살표 차례인지 -> 1인 이유는 ◎는 항상 true
			while (!(arrowArr[tmp].getState())) {
				tmp++;
			}
			if (tmp == len - 1) { //다 깼을때
				if (gm.getLevel() == 1) {
					gm.increaseLife();
					gm.levelUp();
					Arrow arrow2[58] = { Arrow() };
					for (int i = 0; i < 58; i++) {
						arrow2[i].setAttribute(flag_x[i], flag_y[i], flag_type[i]);
						View::drawArrow(arrow2[i]);
					}
					View::printAnnounce(gm);
					playGame(gm, arrow2, 58);
				}
				else {
					system("cls");
					gotoxy(30, 10);
					cout << "clear!!";
				}
				break;
			}
			c = getch();
			switch (c) {
			case UP:
				key = 1;
				break;
			case DOWN:
				key = 2;
				break;
			case LEFT:
				key = 3;
				break;
			case RIGHT:
				key = 4;
				break;
			}
			if (key == arrowArr[tmp].getType()) { //입력된 방향키와 화살표 Type이 같으면
				arrowArr[tmp].setState(false); //false로..
				int tmp_x = arrowArr[tmp].getX();
				int tmp_y = arrowArr[tmp].getY();
				arrowArr[0].setXY(tmp_x, tmp_y);
			}
			else if (key == 1 || key == 2 || key == 3 || key == 4) { //다른 방향키
				if (gm.getLife() > 0) { //life가 0 이상이면 -> life 감소
					gm.decreaseLife();
				}
			}
			system("cls");
			View::printAnnounce(gm);
			for (int i = 0; i < len; i++) {
				if (arrowArr[i].getState())
					View::drawArrow(arrowArr[i]);
			}
			key = 0;
		}
	}
}


// 화살표들의 객체를 생성하고, GameManager 객체를 생성하여 game을 play시킴.
int Game6::game6() {
	Arrow arrowArr[53] = { Arrow() };

	for (int i = 0; i < 53; i++) {
		arrowArr[i].setAttribute(sw_x[i], sw_y[i], sw_type[i]);
		View::drawArrow(arrowArr[i]);
	}

	GameManager gm = GameManager();
	View::printAnnounce(gm);
	playGame(gm, arrowArr, 53);
	return gm.getLife();
}

int Game6::game6_display() {
	system("mode con cols=100 lines=25 | title game6"); // 콘솔창 크기 및 제목 설정
	Game6 game = Game6();
	int life= game.game6();
	return life;
}
