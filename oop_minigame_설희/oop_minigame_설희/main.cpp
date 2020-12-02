#include "seolhui.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

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
void GameManager::resetLife() {
	life = 3;
}
void GameManager::printAnnounce() {
	gotoxy(3, 2);
	SetColor_Red;
	cout << "�� UP  ";
	SetColor_Yellow;
	cout << "�� DOWN  ";
	SetColor_Green;
	cout << "�� LEFT  ";
	SetColor_Blue;
	cout << "�� RIGHT";
	SetColor_White;
	gotoxy(3, 3);
	cout << "LEVEL : " << level << " / LIFE : " << life;
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
void Arrow::drawArrow() {
	gotoxy(x * 2 + 20, y + 5);
	switch (type) {
	case 0: //Ŀ��
		SetColor_White;
		printf("��");
		break;
	case 1: //up
		SetColor_Red;
		printf("��");
		SetColor_White;
		break;
	case 2: //down
		SetColor_Yellow;
		printf("��");
		SetColor_White;
		break;
	case 3: //left 
		SetColor_Green;
		printf("��");
		SetColor_White;
		break;
	case 4: //right
		SetColor_Blue;
		printf("��");
		SetColor_White;
		break;
	}
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
void Arrow::setXY(int x, int y) { // for Ŀ�� XY ����
	this->x = x;
	this->y = y;
}
int Arrow::getX() {
	return x;
}
int Arrow::getY() {
	return y;
}

void playGame(GameManager gm, Arrow arrowArr[], int len) {
	char c;
	int key = 0;
	while (1) {
		if (kbhit()) {
			int tmp = 1; //���� �� ��° ȭ��ǥ �������� -> 1�� ������ �ݴ� �׻� true
			while (!(arrowArr[tmp].getState())) {
				tmp++;
			}
			if (tmp == len-1) { //�� ������
				if (gm.getLevel() == 1) {
					gm.resetLife();
					gm.increaseLife();
					gm.levelUp();
					Arrow arrow2[58] = { Arrow() };
					for (int i = 0; i < 58; i++) {
						arrow2[i].setAttribute(flag_x[i], flag_y[i], flag_type[i]);
						arrow2[i].drawArrow();
					}
					gm.printAnnounce();
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
			if (key == arrowArr[tmp].getType()) { //�Էµ� ����Ű�� ȭ��ǥ Type�� ������
				arrowArr[tmp].setState(false); //false��..
				int tmp_x = arrowArr[tmp].getX();
				int tmp_y = arrowArr[tmp].getY();
				arrowArr[0].setXY(tmp_x, tmp_y);
				system("cls");
				gm.printAnnounce();
				for (int i = 0; i < len; i++) {
					if (arrowArr[i].getState())
						arrowArr[i].drawArrow();
				}
				key = 0;
			}
			else if (key ==1 || key == 2 || key == 3 || key == 4) { //�ٸ� ����Ű
				gm.decreaseLife();
				system("cls");
				if (gm.getLife() > 0) {
					gm.printAnnounce();
					for (int i = 0; i < len; i++) {
						if (arrowArr[i].getState())
							arrowArr[i].drawArrow();
					}
				}
				else {
					gm.resetLife();
					for (int i = 0; i < len; i++) {
						if (gm.getLevel() == 1) {
							arrowArr[i].setAttribute(sw_x[i], sw_y[i], sw_type[i]);
						}
						else {
							arrowArr[i].setAttribute(flag_x[i], flag_y[i], flag_type[i]);
						}
						arrowArr[i].setState(true);
						arrowArr[i].drawArrow();
					}
					gm.printAnnounce();
				}
				key = 0;
			}
		}
	}
}


int main() {
	system("mode con cols=100 lines=25 | title ����"); // �ܼ�â ũ�� �� ���� ����
	//level 1
	Arrow arrowArr[53] = { Arrow() };
	for (int i = 0; i < 53; i++) {
		arrowArr[i].setAttribute(sw_x[i], sw_y[i], sw_type[i]);
		arrowArr[i].drawArrow();
	}
	GameManager gm = GameManager();
	gm.printAnnounce();
	playGame(gm, arrowArr, 53);
	
}
