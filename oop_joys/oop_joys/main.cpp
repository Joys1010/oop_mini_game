#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>

#include "character.h"
#include "classroom.h"
#include "manager.h"
#include "quiz.h"
#include "view.h"




#define LEFT 75        // 방향키 왼쪽
#define RIGHT 77    // 방향키 오른쪽
#define UP 72        // 방향키 위
#define DOWN 80        // 방향키 아래

// 화면 지우기 매크로
#define clrscr() system("cls")

using namespace std;

int main(void) {
    system("mode con cols=100 lines=25 | title 제목"); // 콘솔창 크기 및 제목 설정
    //cols = 가로, lines = 세로 (가로가 세로보다 짧음)

    Manager game5_manager;

    game5_manager.managing();

    return 0;

}