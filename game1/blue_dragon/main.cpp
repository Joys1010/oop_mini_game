#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "game.h" 


using namespace std;

class Setup_for_mini_1 {
private:
	int x;
	int y;
	
public:
	// �ʱ�ȭ�� �Լ� 
	/*Setup_for_mini_1() {
		x = 0;
		y = 0;
	}*/

	void init() {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
		CONSOLE_CURSOR_INFO ConsoleCursor;
		ConsoleCursor.bVisible = false; // false : ����� 
		ConsoleCursor.dwSize = 1;
		SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
		system("mode con cols=100 lines=25 | title 310����6�� �繰�Կ��� ����å ������ ����Ÿ�� ");
	}

	// Ŀ�� ��ġ �̵��Լ�  
	void gotoxy(int x, int y) {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(consoleHandle, pos);
	}

	// ù��°: �ؽ�Ʈ, �ι�°: ���  
	void setColor(int forground, int background) {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
		int code = forground + background * 16;
		SetConsoleTextAttribute(consoleHandle, code);
	}

};


class Game : public Setup_for_mini_1 {
private:
	char tempMap[28][77]; // �� �ӽ������� �迭  

	char map1[28][77] = { 
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000001111111111111111111111111111111111111111111111111111111"},
		{"00000000000000000000010ll000000000000111000nhhhnhhhnhhhnhhhn0088800000000001"},    
		{"00000000000000000000010ll000000000000111000n2hhn3hhn4ahn5hhn0088800nnn00nnn1"}, // 1 : ��ֹ�
		{"00000000000000000000010000000000000001110000000000000000000000887002hh002hh1"}, // 6 : B603
		{"00000000000000000000010ll000s00000000111000nhhhnhhhnhhhnhhhn0088800hhh00hhh1"}, // 7 : B603�� 
		{"00000000000000000000010ll000000000000111000n2hhn3hhn4ahn5hhn0000000nnn00nnn1"}, // l : ����������  // ���� stage�� ���� ��!
		{"00000000000000000000010000000000000000000000000000000000000000000003hh003hh1"}, // 2-1�� �繰�� ,3-2�� �繰��, 4-3�� �繰��, 5-4�� �繰��
		{"0000000000000000000001111000000000000000000000000000000000000000000hhh00hhh1"}, // 8 : toilet
		{"0000000000000000000001111000000000111111111000000000000000000000000nnn00nnn1"}, 
		{"00000000000000000000011110000000001111111110000000000066666666600004hh004hh1"}, // s : �÷��̾�
		{"0000000000000000000001111000000000000000000000000000006666666660000hhh00khh1"}, // 9 : toilet ��
		{"0000000000000000000001111000000n5hhn4ahn3hhn2hhn0000006666666660000nnn00nnn1"}, // h : ���μ�
		{"0000000000000000000001111000000nhhhnhhhnhhhnhhhn0000006666666660000000000001"}, // n : ���μ�
		{"0000000000000000000001111000000000000000000000000000006666669990000000000111"}, // m : �繰�� �� ���� �κ�
		{"0000000000000000000001111111100000000000000000000000006666666660000000000111"}, // k : ��¥ ����å
		{"0000000000000000000001111111100000000000000000000000000000000000000000000111"}, // x : ó�� ��
		{"0000000000000000000001111111111111111100000011000000111111111111111111111111"}, // a : ��¥ ����å
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"}, 
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
		{"0000000000000000000000000000000000000000000000000000000000000000000000000000"},
	};

	
public:
	void drawMap(int* x, int* y) {
		system("cls");
		int h, w; // ����, ����  

		for (h = 0; h < 28; h++) { // ���α��̱���  
			for (w = 0; w <77; w++) { // ���α��̱���  
				char temp = tempMap[h][w]; // �ӽ������� �� ������  
				if (temp == '0') { // �� ����(����)
					setColor(black, black);
					cout << "#";
				}
				else if (temp == '1') { // ��(#)
					setColor(white, white);
					cout << "#";
				}
				else if (temp == 's') { // �÷��̾�(@) 
					*x = w; // �÷��̾� ��ǥ�� ����  
					*y = h;
					setColor(white,black);
					cout << "��";
				}
				else if (temp == 'k') { // ����å
					setColor(lightgray, lightgray);
					cout << "*";
				}
				else if (temp == 'a') { // ����å
					setColor(brown, lightgray);
					cout << "*";
				}
				else if (temp == 'l') { // ����������
					setColor(yellow, yellow);
					cout << "#";
				}
				else if (temp == 'b') { // �ٽ� ���ƿ��� ����1
					setColor(black, black);
					cout << " ";
				}
				else if (temp == 'h') { //�繰�� ����
					setColor(lightgray, lightgray);
					cout << " ";
				}
				else if (temp == 'n') { //�繰�� ����
					setColor(lightgreen, lightgreen);
					cout << " ";
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
					cout << " ";
				}
				else if (temp == '9') { // B603 ��
					setColor(cyan, cyan);
					cout << " ";
				}
				else if (temp == '7') { // B603
					setColor(red, red);
					cout << " ";
				}
				else if (temp == '8') { 
					setColor(lightred, lightred);
					cout << " ";
				}
				
			}
			cout << "\n"; // ���� �� ��������� ��ĭ �ٹٲ� 
		}
		setColor(white, black); // �ٽ� �⺻ �������� ���ƿ��� 
	}

	// ���� ����  
	void gLoop(int mapCode) {
		int x, y; // �÷��̾� ��ǥ ���� ���� ����(x, y) 
		int key = 0; // ���� ���� ���庯��  

		int playing = 1; // 1�̸� �������� ���� ������, 0�̸� ���� ����  


		if (mapCode == 0) {
			memcpy(tempMap, map1, sizeof(tempMap));
		}

		drawMap(&x, &y); // �� ���� �� ��� 
		// �ʿ� ��ǥ �����͸� ����  

		clock_t start, end;
		// ���� ����  
		start = clock();

		Sleep(100);
		int count = 0;
		while (playing) {

			gotoxy(20, 20);
			printf("����������������������������������������������������������������������������������������������������������������");			
			gotoxy(20, 24);
			printf("����������������������������������������������������������������������������������������������������������������");

			drawUI(&x, &y, &key);

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
			for (int i = 1; i < 36; i++) {
				if ((float)(end - start) / CLOCKS_PER_SEC > 35) {
					gotoxy(22, 21);
					cout << "���ѽð� 35�ʰ� �������ϴ�!";
					Sleep(1000);
					break;
				}
				else if ((float)(end - start) / CLOCKS_PER_SEC > i) {
					gotoxy(22, 22);
					cout << i << "��";
				}
			}
		}
		
		if ((float)(end - start) / CLOCKS_PER_SEC > 35) {
			gotoxy(22, 23);
			cout << "Game Fail!";
			Sleep(1500);
		}
		else {
			gotoxy(22, 23);
			cout << "Game Claer!";
			cout << "Ÿ�̸�" << (float)(end - start) / CLOCKS_PER_SEC;
			Sleep(1500);
		}
	}

	/* �÷��̾� ��ǥ�� ������ �Լ�  
	 ���� ��ǥ (x, y), ������ ��ǥ(_x, _y) */

	void move(int* x, int* y, int _x, int _y, int* key, int* go_playing) {
		// �̵��� ��ġ�� �ִ� �� �迭�� ���� �ӽ�����  
		char mapObject = tempMap[*y + _y][*x + _x];
		setColor(white, black); // �� �⺻��  

		if (mapObject == '0') {
			gotoxy(*x, *y); 
			cout << " "; //�����

			setColor(white, black); // �� ����  
			gotoxy(*x + _x, *y + _y); // ������ ��ġ�� �̵� �� �÷��̾� ���  
			cout << "��";

			*x += _x; // ���� ��ǥ������ �ݿ�  
			*y += _y;
		}
		else if (mapObject == 'k') { // �̵��� ��ġ�� ����å�� ������ ȹ��  
			*key += 1; // ����å 1�� ����
			tempMap[*y + _y][*x + _x] = '0'; // ȹ���Ͽ����� ������ �ִ� k�� 0���� ���� 
			gotoxy(*x + _x, *y + _y); // ���谡 �ִ� ��ġ�� ����  
			setColor(lightgray, black); // �� ����  
			cout << " ";
		}
		else if (mapObject == 's') {
			tempMap[*y + _y][*x + _x] = 'n'; // ȹ���Ͽ����� ������ �ִ� k�� 0���� ���� 
			gotoxy(*x + _x, *y + _y); // ���谡 �ִ� ��ġ�� ����  
			cout << " ";
		}
		else if (mapObject == 'l') {
			/*if (*key ==1) {*/
				*go_playing = 0;
			/*}*/
			/*else {
				gotoxy(25, 20);
				cout << "����å ���� ���������� Ÿ�ž���!";
			}*/
		}
		else if (mapObject == '1') { // ���� �ε�����,
			if (*key == 1) {
				gotoxy(*x, *y);
				cout << " "; //�����
				//setcolor(white, black); // �� ���� 

				gotoxy(33, 10); // ������ ��ġ�� �̵� �� �÷��̾� ���  
				cout << "��";
				*x = 33; // ���� ��ǥ������ �ݿ�
				*y = 10;
				cout << " ";
			}

			else {
				gotoxy(*x, *y);
				cout << " "; //�����
				//setcolor(white, black); // �� ���� 

				gotoxy(24, 18); // ������ ��ġ�� �̵� �� �÷��̾� ���  
				cout << "��";
				*x = 24; // ���� ��ǥ������ �ݿ�
				*y = 18;
				cout << " ";
			}
		}
	}

	// ���� �ϴܿ� ��ǥ �� ������ ���� ���  
	void drawUI(int* x, int* y, int* key) {
		setColor(white, black);
		gotoxy(34, 16);
		if (*key == 1) {
			cout << "����å ã�Ҵ�! ";
		}
	}


	int keyControl() {
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
};


int main() {
	
	Game title;
	title.init();
	title.gLoop(0); 
	system("cls");
	title.setColor(white, black); // �� �⺻������ ����  

}






