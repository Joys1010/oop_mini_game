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




#define LEFT 75        // ����Ű ����
#define RIGHT 77    // ����Ű ������
#define UP 72        // ����Ű ��
#define DOWN 80        // ����Ű �Ʒ�

// ȭ�� ����� ��ũ��
#define clrscr() system("cls")

using namespace std;

int main(void) {
    system("mode con cols=100 lines=25 | title ����"); // �ܼ�â ũ�� �� ���� ����
    //cols = ����, lines = ���� (���ΰ� ���κ��� ª��)

    Manager game5_manager;

    game5_manager.managing();

    return 0;

}