#define CRT_SECURE_NO_WARNINGS
#include "MINIGAME.h"
#include <iostream>
#include<Windows.h>

using namespace std;

Game::Game() {	//element �ʱ�ȭ
	srand((unsigned int)time(NULL));

	MAPX = 40;
	MAPY = 25;
	PI = 3.14159265;
	NUM_OF_ITEM = 3;

	comment[0] = "���� ��¥�ϱ�?";
	comment[1] = "�ܹ��Ŵ� b��!";
	comment[2] = "�ڳ�, ���� �������Գ�?";
	comment[3] = "�����!";
	comment[4] = "���� ����";

	//boss
	boss.fig = "��";
	boss.nMoveX = 1;
	boss.nMoveY = 1;
	boss.nDist = 1.1;
	boss.MoveTime = 30;
	boss.OldTime = clock();
	boss.color = LIGHTRED;

	//players
	player.fig = "��";
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
	banana.NewTime = 3; // 5�� ���� ����
	banana.color = YELLOW;

	boss_comment.GET = false;
	boss_comment.TIMER = false;
	boss_comment.NewTime = 3;
	boss_comment.OldTime = clock();

	//ITEMS
	int pos_x;
	int pos_y;
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		pos_x = rand() % MAPX;
		pos_y = rand() % MAPY;
		cau_burger[i].fig = "burger";
		cau_burger[i].nMoveX = pos_x;
		cau_burger[i].nMoveY = pos_y;
		cau_burger[i].GET = false;
		cau_burger[i].OldTime = clock();
		cau_burger[i].TIMER = false;
		cau_burger[i].NewTime = 3; // 5�� ���� ����
		cau_burger[i].color = LIGHTGREEN;
	}
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		pos_x = rand() % MAPX;
		pos_y = rand() % MAPY;
		studentIDcard[i].fig = "��";
		studentIDcard[i].nMoveX = pos_x;
		studentIDcard[i].nMoveY = pos_y;
		studentIDcard[i].GET = false;
		studentIDcard[i].OldTime = clock();
		studentIDcard[i].TIMER = false;
		studentIDcard[i].NewTime = 3; // 5�� ���� ����
		studentIDcard[i].color = LIGHTCYAN;
	}
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		pos_x = rand() % MAPX;
		pos_y = rand() % MAPY;
		book[i]. fig = "�ע�";
		book[i].nMoveX = pos_x;
		book[i].nMoveY = pos_y;
		book[i].GET = false;
		book[i].OldTime = clock();
		book[i].TIMER = false;
		book[i].NewTime = 3; // 5�� ���� ����
		book[i].color = LIGHTMAGENTA;
	}

	int realItem = rand() % NUM_OF_ITEM; //init geuine item
	cau_burger[realItem].GET = true;
	studentIDcard[realItem].GET = true;
	book[realItem].GET = true;
}

Game::~Game() {};

void Game::Update() { //hitby ���� ����
	clock_t CurTime = clock();
	COORD coor_player = { player.nMoveX, player.nMoveY };
	COORD corr_boss = { boss.nMoveX, boss.nMoveY };

	if ((CurTime - boss.OldTime) > boss.MoveTime) {
		boss.OldTime = CurTime;

		double theta = acos(sqrt(pow(coor_player.X - corr_boss.X, 2)) / sqrt(pow(coor_player.X - corr_boss.X, 2) +
			pow(coor_player.Y - corr_boss.Y, 2)));		// �⺻ 1 ��и�
		if (coor_player.Y - corr_boss.Y <= 0 && coor_player.X - corr_boss.X >= 0) { theta = -theta; }	//4 ��и�
		if (coor_player.Y - corr_boss.Y >= 0 && coor_player.X - corr_boss.X <= 0) { theta = PI - theta; } //2 ��и�
		if (coor_player.Y - corr_boss.Y <= 0 && coor_player.X - corr_boss.X <= 0) { theta = PI + theta; } // 3 ��и�
		int distance = sqrt(pow(coor_player.X - corr_boss.X, 2) + pow(coor_player.Y - corr_boss.Y, 2));

		if (boss_comment.GET == false) {
			if ((distance) % 5 == 0) {	//�����Ÿ� �������� �ٰ����� ��Ʈ�� ���� 
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
					boss_comment.GET = false; //�ڸ�Ʈ�� �ڵ����� ����
					boss_comment.TIMER = false;
				}
			}
		}

		boss.nMoveX += boss.nDist * cos(theta);
		boss.nMoveY += boss.nDist * sin(theta);

	}

	if (boss.nMoveX > MAPX)
		boss.nMoveX = corr_boss.X;
	if (boss.nMoveX < 0)
		boss.nMoveX = corr_boss.X;
	if (boss.nMoveY > MAPY)
		boss.nMoveY = corr_boss.Y;
	if (boss.nMoveY < 0)
		boss.nMoveY = corr_boss.Y;


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
		if (GetAsyncKeyState(VK_SPACE)) { //�ν��� ������
			if (banana.GET == true) {
				banana.GET = false;
				banana.nMoveX = player.nMoveX;
				banana.nMoveY = player.nMoveY;
			}
		}

		//�̵��� ���� �Ѿ�� �� �ݴ������� swap��
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
		if (hitby(banana, boss)) {
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


int Game::hitby(Char player, Char boss) {
	if (player.nMoveX == boss.nMoveX && player.nMoveY == boss.nMoveY)
		return 1;
	else
		return 0;
}

int Game::hitby(Item itemA, Char charA) {
	if (itemA.nMoveX == charA.nMoveX && itemA.nMoveY == charA.nMoveY)
		return 1;
	else
		return 0;


}


int Game::life() {
	int life = 5;
	char next;
	while (1) {
		Game game;
		game.gLoop(0);
		life--;
		if (game.succeed() || life == 0)
			break;
		GotoXY(MAPX / 2 - 5, MAPY / 2);
		cout << "input 'y' and ENTER to retry" << endl;
		GotoXY(MAPX / 2 - 5, MAPY / 2 +  2
		);
		cin >> next;
	}
	GotoXY(MAPX / 2 - 5, MAPY / 2 - 1);
	cout << "--------------------" << endl;
	GotoXY(MAPX / 2 - 5, MAPY / 2);
	cout << "Go back to next stage!" << endl;
	GotoXY(MAPX / 2 - 5, MAPY / 2 + 1);
	cout << "---------------------" << endl;

	return life;
}

void Game::gLoop(int mapCode) {
	Console();

	ScreenInit();
	srand((unsigned int)time(NULL));


	while (1) {
		Update();
		Draw();
		//end = clock();
		if (hitby(player, boss)) {
			break;
		}
		if (succeed())
			break;
	}

	ScreenRelease();
}


void Game::GameScreen() {

	for (int i = 0; i < MAPY; i++) {
		GotoXY(MAPX + 1, i);
		cout << "|";
	}

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
	if (banana.TIMER == false) {
		if (banana.GET == false) {
			GotoXY(banana.nMoveX, banana.nMoveY);
			setColor(banana.color, 0);
			cout << banana.fig;
			setColor(WHITE, 0);
		}
		else {
			setColor(banana.color, 0);
			GotoXY(MAPX + 3, 5);
			cout << banana.fig;
			setColor(WHITE, 0);
			GotoXY(MAPX + 3, 6);
			cout << "banana";
			setColor(WHITE, 0);
		}
	}

	for (int i = 0; i < NUM_OF_ITEM; i++) {

		if (cau_burger[i].TIMER == true)
			setColor(DARKGRAY, LIGHTGRAY);
		else
			setColor(cau_burger[i].color, RED);

		if (cau_burger[i].GET == true && cau_burger[i].TIMER == true) {
			GotoXY(MAPX + 3, 9);
			setColor(cau_burger[i].color, RED);
			cout << "burger\n";
		}
		else {
			GotoXY(cau_burger[i].nMoveX, cau_burger[i].nMoveY);
			cout << cau_burger[i].fig;
		}

		if (studentIDcard[i].TIMER == true)
			setColor(LIGHTGRAY, 0);
		else
			setColor(studentIDcard[i].color, 0);

		if (studentIDcard[i].GET == true && studentIDcard[i].TIMER == true) {
			GotoXY(MAPX + 3, 11);
			setColor(studentIDcard[i].color, 0);
			cout << studentIDcard[i].fig;
			cout << "IDcard";
		}
		else {
			GotoXY(studentIDcard[i].nMoveX, studentIDcard[i].nMoveY);
			cout << studentIDcard[i].fig;
		}

		if (book[i].TIMER == true)
			setColor(LIGHTGRAY, 0);
		else
			setColor(book[i].color, 0);

		if (book[i].GET == true && book[i].TIMER == true) {
			GotoXY(MAPX + 3, 14);
			setColor(book[i].color, 0);
			cout << book[i].fig;
			cout << "book";
		}
		else {
			GotoXY(book[i].nMoveX, book[i].nMoveY);
			cout << book[i].fig;
		}
		setColor(WHITE, 0);
	}

}

void Game::Draw() {
	ScreenClear();

	GameScreen();

	ScreenFlipping();
}


int Game::succeed() {
	int count = 0;
	for (int i = 0; i < NUM_OF_ITEM; i++) {
		if (studentIDcard[i].GET == true && studentIDcard[i].TIMER == true)
			count++;
		if (book[i].GET == true && book[i].TIMER == true)
			count++;
		if (cau_burger[i].GET == true && cau_burger[i].TIMER == true)
			count++;
	}
	if (count == 3)
		return 1;
	else
		return 0;
}