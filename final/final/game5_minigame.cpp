#define CRT_SECURE_NO_WARNINGS
#include "game5_minigame.h"
#include "game5_Scene.h"
#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include <cmath>

using namespace std;
//#pragma comment(lib,"winmm") 

Game5::Game5() {	//element 초기화
	MAPX = 50;
	MAPY = 25;
	PI = 3.14159265;
	NUM_OF_ITEM = 3;

	comment[0] = "뭐가 진짜일까?";
	comment[1] = "햄버거는 b지!";
	comment[2] = "자네, 수업 들으러왔나?";
	comment[3] = "멈춰랏!";
	comment[4] = "눈누 난나";

	//boss
	boss.fig = "♨";
	//boss.HP = 13;
	boss.nMoveX = 1;
	boss.nMoveY = 1;
	boss.nDist = 1.1;
	boss.MoveTime = 30;
	boss.OldTime = clock();

	boss.color = LIGHTRED;

	//players
	player.fig = "◎";
	//player.HP = 13;
	player.nMoveX = 40;
	player.nMoveY = 20;
	player.nDist = 1;
	player.MoveTime = 30;
	player.OldTime = clock();

	banana.fig = "<<<";
	banana.nMoveX = 20;
	banana.nMoveY = 15;
	banana.GET = true;
	banana.OldTime = clock();
	banana.TIMER = false;
	banana.NewTime = 3; // 5초 동안 유지
	banana.color = YELLOW;

	boss_comment.GET = false;
	boss_comment.TIMER = false;
	boss_comment.NewTime = 3;
	boss_comment.OldTime = clock();

	//ITEMS
	int pos_x;
	int pos_y;
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		pos_x = rand() % 50;
		pos_y = rand() % 25;
		cau_burger[i].fig = "burger";
		cau_burger[i].nMoveX = pos_x;
		cau_burger[i].nMoveY = pos_y;
		cau_burger[i].GET = false;
		cau_burger[i].OldTime = clock();
		cau_burger[i].TIMER = false;
		cau_burger[i].NewTime = 3; // 5초 동안 유지
		cau_burger[i].color = LIGHTGREEN;
	}
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		pos_x = rand() % 50;
		pos_y = rand() % 25;
		studentIDcard[i].fig = "■";
		studentIDcard[i].nMoveX = pos_x;
		studentIDcard[i].nMoveY = pos_y;
		studentIDcard[i].GET = false;
		studentIDcard[i].OldTime = clock();
		studentIDcard[i].TIMER = false;
		studentIDcard[i].NewTime = 3; // 5초 동안 유지
		studentIDcard[i].color = LIGHTCYAN;
	}
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		pos_x = rand() % 50;
		pos_y = rand() % 25;
		book[i]. fig = "§▤";
		book[i].nMoveX = pos_x;
		book[i].nMoveY = pos_y;
		book[i].GET = false;
		book[i].OldTime = clock();
		book[i].TIMER = false;
		book[i].NewTime = 3; // 5초 동안 유지
		book[i].color = LIGHTMAGENTA;
	}

	int realItem = rand() % 3; //init geuine item
	cau_burger[realItem].GET = true;
	studentIDcard[realItem].GET = true;
	book[realItem].GET = true;
}

Game5::~Game5() {};

void Game5::Update() { //hitby 따로 빼기
	clock_t CurTime = clock();
	COORD coor_player = { player.nMoveX, player.nMoveY };
	COORD corr_boss = { boss.nMoveX, boss.nMoveY };

	if ((CurTime - boss.OldTime) > boss.MoveTime) {
		boss.OldTime = CurTime;

		double theta = acos(sqrt(pow(coor_player.X - corr_boss.X, 2)) / sqrt(pow(coor_player.X - corr_boss.X, 2) +
			pow(coor_player.Y - corr_boss.Y, 2)));		// 기본 1 사분면
		if (coor_player.Y - corr_boss.Y <= 0 && coor_player.X - corr_boss.X >= 0) { theta = -theta; }	//4 사분면
		if (coor_player.Y - corr_boss.Y >= 0 && coor_player.X - corr_boss.X <= 0) { theta = PI - theta; } //2 사분면
		if (coor_player.Y - corr_boss.Y <= 0 && coor_player.X - corr_boss.X <= 0) { theta = PI + theta; } // 3 사분면
		int distance = sqrt(pow(coor_player.X - corr_boss.X, 2) + pow(coor_player.Y - corr_boss.Y, 2));

		if (boss_comment.GET == false) {
			if ((distance) % 5 == 0) {	//일정거리 보스에게 다가가면 힌트를 얻음 
				int randomB = rand() % 5;
				boss_comment.fig = comment[randomB];
				boss_comment.GET = true;
				boss_comment.OldTime = clock();
				boss_comment.TIMER = true;
			}
		}
		else {
			if (boss_comment.TIMER == true) {
				if ((float)(CurTime - boss_comment.OldTime) / CLOCKS_PER_SEC > boss_comment.NewTime) {
					boss_comment.GET = false; //코멘트가 자동으로 꺼짐
					boss_comment.TIMER = false;
				}
			}
		}

		boss.nMoveX += boss.nDist * cos(theta);
		boss.nMoveY += boss.nDist * sin(theta);

	}


	if ((CurTime - player.OldTime) > player.MoveTime) {
		player.OldTime = CurTime;
		int tempX = player.nMoveX;
		if (GetAsyncKeyState(VK_LEFT))
			player.nMoveX -= player.nDist;
		if (GetAsyncKeyState(VK_UP))
			player.nMoveY -= player.nDist;
		if (GetAsyncKeyState(VK_DOWN))
			player.nMoveY += player.nDist;
		if (GetAsyncKeyState(VK_RIGHT))
			player.nMoveX += player.nDist;
		if (GetAsyncKeyState(VK_SPACE)) { //부스터 아이템
			if (banana.GET == true) {
				banana.GET = false;
				banana.nMoveX = player.nMoveX;
				banana.nMoveY = player.nMoveY;
			}
		}

		//이동이 맵을 넘어갔을 때 반대편으로 swap됨
		if (player.nMoveX >= MAPX)
			player.nMoveX = player.nMoveX / MAPX;
		if (player.nMoveX < 0)
			player.nMoveX = MAPX + player.nMoveX;
		if (player.nMoveY >= MAPY)
			player.nMoveY = player.nMoveY / MAPY;
		if (player.nMoveY < 0)
			player.nMoveY = MAPY + player.nMoveY;
	}

	if (banana.GET == false) {
		if (banana.nMoveX == boss.nMoveX && banana.nMoveY == boss.nMoveY) {
			boss.nDist = -0.7;
			banana.GET = true;
			banana.OldTime = clock();
			banana.TIMER = true;
		}
	}

	if (banana.TIMER == true) {
		if ((float)(CurTime - banana.OldTime) / CLOCKS_PER_SEC > banana.NewTime) {
			boss.nDist = 1.1;
		}
	}

	for (int i = 0; i < NUM_OF_ITEM; i++) {
		if (cau_burger[i].TIMER == false) {
			if (hitby(cau_burger[i], boss)) {
				boss.nMoveX = corr_boss.X;
				boss.nMoveY = corr_boss.Y;
			}
		}
		if (studentIDcard[i].TIMER == false) {
			if (hitby(studentIDcard[i], boss)) {
				boss.nMoveX = corr_boss.X;
				boss.nMoveY = corr_boss.Y;
			}
		}
		if (book[i].TIMER == false) {
			if (hitby(book[i], boss)) {
				boss.nMoveX = corr_boss.X;
				boss.nMoveY = corr_boss.Y;
			}
		}
	}

	for (int i = 0; i < NUM_OF_ITEM; i++) {
		if (cau_burger[i].TIMER == false) {
			if (hitby(cau_burger[i], player)) {
				cau_burger[i].TIMER = true;
			}
		}
		if (studentIDcard[i].TIMER == false) {
			if (hitby(studentIDcard[i], player)) {
				studentIDcard[i].TIMER = true;
			}
		}
		if (book[i].TIMER == false) {
			if (hitby(book[i], player)) {
				book[i].TIMER = true;
			}
		}
	}
}


int Game5::hitby(Char player, Char boss) {
	if (player.nMoveX == boss.nMoveX && player.nMoveY == boss.nMoveY)
		return 1;
	else
		return 0;
}

int Game5::hitby(Item itemA, Char charA) {
	if (itemA.nMoveX == charA.nMoveX && itemA.nMoveY == charA.nMoveY)
		return 1;
	else
		return 0;
}

void Game5::gLoop(int mapCode) {
	Console();

	ScreenInit();
	Scene();

	srand((unsigned int)time(NULL));
	//time_t start, end;
	//start = clock();

	while (1) {
		Update();
		Draw();
		//end = clock();
		if (hitby(player, boss)) {
			break;
		}
		if (succeed())
			break;
		//if ((float)(end - start) / CLOCKS_PER_SEC > 30) {
			//break;
		//}
	}
	cout << "Go back to class!" << endl;
	//ScreenRelease();
}


void Game5::GameScreen() {

	GotoXY(boss.nMoveX, boss.nMoveY);
	setColor(boss.color, 0);
	cout << boss.fig;
	setColor(WHITE, 0);
	GotoXY(player.nMoveX, player.nMoveY);
	cout << player.fig;
	if (boss_comment.TIMER == true && boss_comment.GET == true) {
		GotoXY(boss.nMoveX + 1, boss.nMoveY - 1);
		cout << boss_comment.fig;
	}
	if (banana.GET == false) {
		GotoXY(banana.nMoveX, banana.nMoveY);
		setColor(banana.color, 0);
		cout << banana.fig;
		setColor(WHITE, 0);
	}

	for (int i = 0; i < NUM_OF_ITEM; i++) {

		GotoXY(cau_burger[i].nMoveX, cau_burger[i].nMoveY);
		if (cau_burger[i].TIMER == true)
			setColor(DARKGRAY, LIGHTGRAY);
		else
			setColor(cau_burger[i].color, RED);

		if (cau_burger[i].GET == true && cau_burger[i].TIMER == true) {
		}
		else
			cout << cau_burger[i].fig;

		GotoXY(studentIDcard[i].nMoveX, studentIDcard[i].nMoveY);
		if (studentIDcard[i].TIMER == true)
			setColor(LIGHTGRAY, 0);
		else
			setColor(studentIDcard[i].color, 0);
		if (studentIDcard[i].GET == true && studentIDcard[i].TIMER == true) {
		}
		else
			cout << studentIDcard[i].fig;

		GotoXY(book[i].nMoveX, book[i].nMoveY);
		if (book[i].TIMER == true)
			setColor(LIGHTGRAY, 0);
		else
			setColor(book[i].color, 0);

		if (book[i].GET == true && book[i].TIMER == true) {
		}
		else
			cout << book[i].fig;
		setColor(WHITE, 0);
	}

}

void Game5::Draw() {
	

	GameScreen();
	ScreenClear();

	//ScreenFlipping();
}



int Game5::succeed() {
	int count = 0;
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		if (studentIDcard[i].GET == true && studentIDcard[i].TIMER == true)
			count++;
		if (studentIDcard[i].GET == true && studentIDcard[i].TIMER == true)
			count++;
		if (studentIDcard[i].GET == true && studentIDcard[i].TIMER == true)
			count++;
	}
	if (count == 3)
		return 1;
	else
		return 0;
}
