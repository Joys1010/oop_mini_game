#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "game1.h" 


using namespace std;

void Setup_for_mini_1::init()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false; // false : ����� 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	system("mode con cols=100 lines=25 | title 310����6�� �繰�Կ��� ����å ������ ����Ÿ�� ");
}

// Ŀ�� ��ġ �̵��Լ�  
void Setup_for_mini_1::gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// ù��°: �ؽ�Ʈ, �ι�°: ���  
void Setup_for_mini_1::setColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}


void Game1::drawMap(int* x, int* y) {
	system("cls");
	int h, w; // ����, ����  

	for (h = 0; h < 18; h++) { // ���α��̱���  
		for (w = 0; w < 77; w++) { // ���α��̱���  
			char temp = tempMap[h][w]; // �ӽ������� �� ������  
			if (temp == '0') { // �� ����(����)
				setColor(black, black);
				cout << " ";
			}
			else if (temp == '1') { // ��(#)
				setColor(white, white);
				cout << "*";
			}
			else if (temp == 's') { // �÷��̾�(@) 
				*x = w; // �÷��̾� ��ǥ�� ����  
				*y = h;
				setColor(white, black);
				cout << "@";
			}
			else if (temp == 'k') { // ����å
				setColor(lightgray, lightgray);
				cout << "*";
			}
			else if (temp == 'a') { // ����å
				setColor(lightgray, lightgray);
				cout << "*";
			}
			else if (temp == 'l') { // ����������
				setColor(yellow, yellow);
				cout << "#";
			}
			else if (temp == 'b') { // �ٽ� ���ƿ��� ����1
				setColor(black, black);
				cout << "*";
			}
			else if (temp == 'h') { //�繰�� ����
				setColor(lightgray, lightgray);
				cout << "*";
			}
			else if (temp == 'n') { //�繰�� ����
				setColor(lightgreen, lightgreen);
				cout << "*";
			}
			else if (temp == '2') { //�繰�� ��ȣ 1
				setColor(black, lightgray);
				cout << "1";
			}
			else if (temp == '3') { //�繰�� ��ȣ 2
				setColor(black, lightgray);
				cout << "2";
			}
			else if (temp == '4') { //�繰�� ��ȣ 3
				setColor(black, lightgray);
				cout << "3";
			}
			else if (temp == '5') { //�繰�� ��ȣ 4
				setColor(black, lightgray);
				cout << "4";
			}
			else if (temp == '6') {  // B603
				setColor(lightcyan, lightcyan);
				cout << "*";
			}
			else if (temp == '9') { // B603 ��
				setColor(cyan, cyan);
				cout << "*";
			}
			else if (temp == '7') { // B603
				setColor(red, red);
				cout << "*";
			}
			else if (temp == '8') {
				setColor(lightred, lightred);
				cout << "*";
			}
			else if (temp == 'd') {
				setColor(lightgreen, lightgreen);
				cout << "*";
			}

		}
		cout << "\n"; // ���� �� ��������� ��ĭ �ٹٲ� 
	}
	setColor(white, black); // �ٽ� �⺻ �������� ���ƿ��� 
}


// ���� ����  
int Game1::gLoop(int mapCode) {
	int x, y; // �÷��̾� ��ǥ ���� ���� ����(x, y) 
	int key = 0; // ����å ���� ���庯��  
	int playing = 1; // 1�̸� ������, 0�̸� ���� ����  
	int life = 5;

	if (mapCode == 0) {
		memcpy(tempMap, map1, sizeof(tempMap));
	}

	drawMap(&x, &y); // �� ���� �� ��� 
	// �ʿ� ��ǥ �����͸� ����  



	gotoxy(21, 21);
	cout << "������������������������������������������������������������������������������������������������������������";
	gotoxy(20, 22);
	cout << "  �� ��𿴴���,,,? �и� 3�� �繰���̾��� �� ������ ..  ";
	gotoxy(21, 23);
	cout << "������������������������������������������������������������������������������������������������������������";

	gotoxy(20, 19);
	cout << "  TIMER :  ";

	clock_t start, end;
	// ���� ����  
	start = clock();
	switch (keyControl()) {
	case UP:
		start = clock();
	case DOWN:
		start = clock();
	case LEFT:
		start = clock();
	case RIGHT:
		start = clock();
	}

	int count = 0;
	while (playing && life != 0) {

		drawUI(&x, &y, &key);

		gotoxy(8, 1);
		cout << "������������������";
		gotoxy(8, 2);
		setColor(red, black);
		cout << "  �� ";
		setColor(white, black);
		cout << life;
		gotoxy(8, 3);
		cout << "������������������";

		switch (keyControl()) {
		case UP:
			move(&x, &y, 0, -1, &key, &playing); // ����x, ����y, x�������� �̵��� ĭ, y�������� �̵��� ĭ  
			break;

		case DOWN:
			move(&x, &y, 0, 1, &key, &playing); // x��ġ�� �״��, y��ġ�� +1 (�Ʒ���) 
			break;

		case RIGHT:
			move(&x, &y, 1, 0, &key, &playing); // x��ġ�� +1, y�� �״��(������) 
			break;

		case LEFT:
			move(&x, &y, -1, 0, &key, &playing); // x��ġ�� -1, y�� �״��(����) 
			break;

		case SUBMIT:
			playing = 0; // 0�� �Ǹ� �ݺ� ����  
		}
		count++;
		end = clock();
		for (int i = 1; i < 21; i++) {
			if ((float)(end - start) / CLOCKS_PER_SEC > i) {
				gotoxy(20, 19);
				cout << "  TIMER :  " << i << "�� (���ѽð� : 20��)";
				continue;
			}
		}
		if ((float)(end - start) / CLOCKS_PER_SEC >= 20) {
			life--;
			start = clock();
			end = clock();

		}
	}

	if ((float)(end - start) / CLOCKS_PER_SEC >= 20) {
		system("cls");
		gotoxy(22, 23);
		cout << "Game Fail!"; // ����� ������ �ϸ� �ȴ�..
		Sleep(1500);
	}
	else {
		system("cls");
		gotoxy(30, 10);
		cout << "    GAME CLEAR!\n";
		gotoxy(30, 11);
		cout << "������������������������������������\n";
		gotoxy(30, 12);
		cout << "���� TIME RECORD : " << (float)(end - start) / CLOCKS_PER_SEC << "\n" << "��";
		gotoxy(30, 13);
		cout << "���� SAVED LIFE(��) : " << life << "\n";
		Sleep(1500);
		return life;
	}
}

/* �÷��̾� ��ǥ�� ������ �Լ�
 ���� ��ǥ (x, y), ������ ��ǥ(_x, _y) */

void Game1::move(int* x, int* y, int _x, int _y, int* key, int* go_playing) {
	// �̵��� ��ġ�� �ִ� �� �迭�� ���� �ӽ�����  
	char mapObject = tempMap[*y + _y][*x + _x];
	setColor(white, black); // �� �⺻��  

	if (mapObject == '0') {
		gotoxy(*x, *y);
		cout << " "; //�����

		setColor(white, black); // �� ����  
		gotoxy(*x + _x, *y + _y); // ������ ��ġ�� �̵� �� �÷��̾� ���  
		cout << "@";

		*x += _x; // ���� ��ǥ������ �ݿ�  
		*y += _y;
	}
	else if (mapObject == 'k') { // �̵��� ��ġ�� ����å�� ������ ȹ��  
		*key += 1; // ����å 1�� ����
		tempMap[*y + _y][*x + _x] = 'h'; // ȹ���Ͽ����� ������ �ִ� k�� 0���� ���� 
		setColor(lightgray, lightgray); // �� ����  
		gotoxy(*x + _x, *y + _y); // ���谡 �ִ� ��ġ�� ����  
		setColor(lightgray, lightgray); // �� ����  
		cout << "*";
		setColor(white, black); // �� ����  
	}
	else if (mapObject == 'a') {
		tempMap[*y + _y][*x + _x] = 'a'; // ȹ���Ͽ����� ������ �ִ� k�� a���� ���� 
		setColor(lightgray, lightgray); // �� ����  
		gotoxy(*x + _x, *y + _y); // ���谡 �ִ� ��ġ�� ����  
		cout << "*";
		gotoxy(22, 22);
		setColor(white, black); // �� ����  
		cout << " �ٸ� ����� �繰�����ݾ� �ФѤ�                    ";
	}
	else if (mapObject == 'l') {
		if (*key == 1) {
			*go_playing = 0;
		}
		else {
			gotoxy(22, 22);
			cout << " ��! �繰�Կ��� ����å �� �����Ա� �ФѤ�                ";
		}
	}
	else if (mapObject == '1' || mapObject == '6' || mapObject == '7' || mapObject == '8' || mapObject == '9' || mapObject == 'n' || mapObject == 'd') { // ���� �ε�����,
		gotoxy(*x, *y);
		cout << " "; //�����
		setColor(white, black); // �� ���� 

		gotoxy(48, 17); // ������ ��ġ�� �̵� �� �÷��̾� ���  
		cout << "@";
		*x = 48; // ���� ��ǥ������ �ݿ�
		*y = 17;
		//cout << " ";

	}
}


// ���� �ϴܿ� ��ǥ �� ������ ���� ���  
void Game1::drawUI(int* x, int* y, int* key) {
	gotoxy(22, 22);
	if (*key >= 1) {
		cout << " �� !! ����å ã�Ҵ�!                                 ";
		gotoxy(55, 19);
		cout << "      * ����å ȹ�� *";
	}

}


int Game1::keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') { // �����̽���(����)�� ���� ��ư  
		return SUBMIT;
	}
}

