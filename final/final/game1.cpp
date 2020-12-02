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
                setColor(brown, lightgray);
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
                cout << "*";
            }
            else if (temp == '3') { //�繰�� ��ȣ 2
                setColor(black, lightgray);
                cout << "*";
            }
            else if (temp == '4') { //�繰�� ��ȣ 3
                setColor(black, lightgray);
                cout << "*";
            }
            else if (temp == '5') { //�繰�� ��ȣ 4
                setColor(black, lightgray);
                cout << "*";
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

        }
        cout << "\n"; // ���� �� ��������� ��ĭ �ٹٲ� 
    }
    setColor(white, black); // �ٽ� �⺻ �������� ���ƿ��� 
}

// ���� ����  
void Game1::gLoop(int mapCode) {
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

        //gotoxy(20, 20);
        //printf("����������������������������������������������������������������������������������������������������������������");         
        //gotoxy(20, 24);
        //printf("����������������������������������������������������������������������������������������������������������������");

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
        if (*key == 1) {
            *go_playing = 0;
        }
        else {
            gotoxy(25, 20);
            cout << "����å ���� ���������� Ÿ�ž���!";
        }
    }
    else if (mapObject == '1') { // ���� �ε�����,
        if (*key == 1) {
            gotoxy(*x, *y);
            cout << " "; //�����
            //setcolor(white, black); // �� ���� 

            gotoxy(48, 25); // ������ ��ġ�� �̵� �� �÷��̾� ���  
            cout << "@";
            *x = 48; // ���� ��ǥ������ �ݿ�
            *y = 25;
            cout << " ";
        }

        else {
            gotoxy(*x, *y);
            cout << " "; //�����
            //setcolor(white, black); // �� ���� 

            gotoxy(48, 45); // ������ ��ġ�� �̵� �� �÷��̾� ���  
            cout << "@";
            *x = 48; // ���� ��ǥ������ �ݿ�
            *y = 45;
            cout << " ";
        }
    }
}

// ���� �ϴܿ� ��ǥ �� ������ ���� ���  
void Game1::drawUI(int* x, int* y, int* key) {
    setColor(white, black);
    gotoxy(20, 22);
    if (*key == 1) {
        cout << "����å ã�Ҵ�! ";
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