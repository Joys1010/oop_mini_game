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
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = false; // false : 숨기기 
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
    system("mode con cols=100 lines=25 | title 310지하6층 사물함에서 전공책 꺼내서 엘베타기 ");
}

// 커서 위치 이동함수  
void Setup_for_mini_1::gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

// 첫번째: 텍스트, 두번째: 배경  
void Setup_for_mini_1::setColor(int forground, int background) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}


void Game1::drawMap(int* x, int* y) {
    system("cls");
    int h, w; // 세로, 가로  

    for (h = 0; h < 18; h++) { // 세로길이까지  
        for (w = 0; w < 77; w++) { // 가로길이까지  
            char temp = tempMap[h][w]; // 임시저장한 맵 데이터  
            if (temp == '0') { // 빈 공간(공백)
                setColor(black, black);
                cout << " ";
            }
            else if (temp == '1') { // 벽(#)
                setColor(white, white);
                cout << "*";
            }
            else if (temp == 's') { // 플레이어(@) 
                *x = w; // 플레이어 좌표값 저장  
                *y = h;
                setColor(white, black);
                cout << "@";
            }
            else if (temp == 'k') { // 전공책
                setColor(lightgray, lightgray);
                cout << "*";
            }
            else if (temp == 'a') { // 전공책
                setColor(brown, lightgray);
                cout << "*";
            }
            else if (temp == 'l') { // 엘레베이터
                setColor(yellow, yellow);
                cout << "#";
            }
            else if (temp == 'b') { // 다시 돌아오는 지점1
                setColor(black, black);
                cout << "*";
            }
            else if (temp == 'h') { //사물함 가로
                setColor(lightgray, lightgray);
                cout << "*";
            }
            else if (temp == 'n') { //사물함 세로
                setColor(lightgreen, lightgreen);
                cout << "*";
            }
            else if (temp == '2') { //사물함 번호 1
                setColor(black, lightgray);
                cout << "*";
            }
            else if (temp == '3') { //사물함 번호 2
                setColor(black, lightgray);
                cout << "*";
            }
            else if (temp == '4') { //사물함 번호 3
                setColor(black, lightgray);
                cout << "*";
            }
            else if (temp == '5') { //사물함 번호 4
                setColor(black, lightgray);
                cout << "*";
            }
            else if (temp == '6') {  // B603
                setColor(lightcyan, lightcyan);
                cout << "*";
            }
            else if (temp == '9') { // B603 문
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
        cout << "\n"; // 한줄 다 출력했으면 한칸 줄바꿈 
    }
    setColor(white, black); // 다시 기본 색상으로 돌아오기 
}

// 게임 루프  
void Game1::gLoop(int mapCode) {
    int x, y; // 플레이어 좌표 저장 변수 선언(x, y) 
    int key = 0; // 열쇠 갯수 저장변수  

    int playing = 1; // 1이면 동상으로 가는 게임중, 0이면 게임 종료  

    if (mapCode == 0) {
        memcpy(tempMap, map1, sizeof(tempMap));
    }

    drawMap(&x, &y); // 맵 설정 후 출력 
    // 맵에 좌표 포인터를 전달  

    clock_t start, end;
    // 게임 루프  
    start = clock();

    Sleep(100);
    int count = 0;
    while (playing) {

        //gotoxy(20, 20);
        //printf("┌──────────────────────────────────────────────────────┐");         
        //gotoxy(20, 24);
        //printf("└──────────────────────────────────────────────────────┘");

        drawUI(&x, &y, &key);

        switch (keyControl()) {
        case UP:
            move(&x, &y, 0, -1, &key, &playing); // 실제x, 실제y, x방향으로 이동할 칸, y방향으로 이동할 칸  
            break;

        case DOWN:
            move(&x, &y, 0, 1, &key, &playing); // x위치는 그대로, y위치는 +1 (아래로) 
            break;

        case RIGHT:
            move(&x, &y, 1, 0, &key, &playing); // x위치는 +1, y는 그대로(오른쪽) 
            break;

        case LEFT:
            move(&x, &y, -1, 0, &key, &playing); // x위치는 -1, y는 그대로(왼쪽) 
            break;

        case SUBMIT:
            playing = 0; // 0이 되면 반복 종료  
        }
        count++;
        end = clock();
        for (int i = 1; i < 36; i++) {
            if ((float)(end - start) / CLOCKS_PER_SEC > 35) {
                gotoxy(22, 21);
                cout << "제한시간 35초가 지났습니다!";
                Sleep(1000);
                break;
            }
            else if ((float)(end - start) / CLOCKS_PER_SEC > i) {
                gotoxy(22, 22);
                cout << i << "초";
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
        cout << "타이머" << (float)(end - start) / CLOCKS_PER_SEC;
        Sleep(1500);
    }
}

/* 플레이어 좌표를 조작할 함수
 원래 좌표 (x, y), 증감할 좌표(_x, _y) */

void Game1::move(int* x, int* y, int _x, int _y, int* key, int* go_playing) {
    // 이동할 위치에 있는 맵 배열의 문자 임시저장  
    char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black); // 색 기본값  

    if (mapObject == '0') {
        gotoxy(*x, *y);
        cout << " "; //지우기

        setColor(white, black); // 색 설정  
        gotoxy(*x + _x, *y + _y); // 증감한 위치로 이동 후 플레이어 출력  
        cout << "@";

        *x += _x; // 실제 좌표값으로 반영  
        *y += _y;
    }
    else if (mapObject == 'k') { // 이동할 위치에 전공책이 있으면 획득  
        *key += 1; // 전공책 1개 증가
        tempMap[*y + _y][*x + _x] = '0'; // 획득하였으면 기존에 있던 k를 0으로 설정 
        gotoxy(*x + _x, *y + _y); // 열쇠가 있는 위치를 지움  
        setColor(lightgray, black); // 색 설정  
        cout << " ";
    }
    else if (mapObject == 's') {
        tempMap[*y + _y][*x + _x] = 'n'; // 획득하였으면 기존에 있던 k를 0으로 설정 
        gotoxy(*x + _x, *y + _y); // 열쇠가 있는 위치를 지움  
        cout << " ";
    }
    else if (mapObject == 'l') {
        if (*key == 1) {
            *go_playing = 0;
        }
        else {
            gotoxy(25, 20);
            cout << "전공책 갖고 엘레베이터 타셔야죠!";
        }
    }
    else if (mapObject == '1') { // 벽에 부딪히면,
        if (*key == 1) {
            gotoxy(*x, *y);
            cout << " "; //지우기
            //setcolor(white, black); // 색 설정 

            gotoxy(48, 25); // 증감한 위치로 이동 후 플레이어 출력  
            cout << "@";
            *x = 48; // 실제 좌표값으로 반영
            *y = 25;
            cout << " ";
        }

        else {
            gotoxy(*x, *y);
            cout << " "; //지우기
            //setcolor(white, black); // 색 설정 

            gotoxy(48, 45); // 증감한 위치로 이동 후 플레이어 출력  
            cout << "@";
            *x = 48; // 실제 좌표값으로 반영
            *y = 45;
            cout << " ";
        }
    }
}

// 게임 하단에 좌표 및 아이템 정보 출력  
void Game1::drawUI(int* x, int* y, int* key) {
    setColor(white, black);
    gotoxy(20, 22);
    if (*key == 1) {
        cout << "전공책 찾았다! ";
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
    else if (temp == ' ') { // 스페이스바(공백)이 선택 버튼  
        return SUBMIT;
    }
}