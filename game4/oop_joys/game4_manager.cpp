#include <iostream>
#include <utility>
#include <windows.h>
#include <Windows.h>
#include <conio.h>

#include "manager.h"
#include "quiz.h"
#include "character.h"
#include "classroom.h"
#include "view.h"

#define LEFT 75        // ����Ű ����
#define RIGHT 77    // ����Ű ������
#define UP 72        // ����Ű ��
#define DOWN 80        // ����Ű �Ʒ�

void gotoxy(int x, int y) {
    
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Manager::managing() {


    //variable setting
    int roomNum = -1;
    int room = -1;
    vector <vector <int>> map;
    string try_answer;
    bool correctness = false;
    bool meetProf = false;

    //player setting
    Character player("joys", "20184374", "CS", 23);

    //quiz settingcj
    Quiz quiz1;
    Quiz quiz2;
    Quiz quiz3;
    Quiz quiz4;
    Quiz quiz5;
    Quiz quiz6;
    Quiz quiz7;
    Quiz quiz8;
    Quiz quiz9;

    quiz1.question = "1?";
    quiz1.answer = "1";

    quiz2.question = "2?";
    quiz2.answer = "2";

    quiz3.question = "3?";
    quiz3.answer = "3";

    quiz4.question = "4?";
    quiz4.answer = "4";

    quiz5.question = "5?";
    quiz5.answer = "5";

    quiz6.question = "6?";
    quiz6.answer = "6";

    quiz7.question = "7?";
    quiz7.answer = "7";

    quiz8.question = "8?";
    quiz8.answer = "8";

    quiz9.question = "9?";
    quiz9.answer = "9";


    //classroom setting
    Classroom room1(10, 10, "OOP", "BongBong", quiz1);
    Classroom room2(30, 20, "Linux", "Son", quiz2);
    Classroom room3(31, 56, "IOT", "Park", quiz3);
    Classroom room4(44, 72, "CC", "Park", quiz4);
    Classroom room5(58, 60, "Capstone", "Park", quiz5);
    Classroom room6(34, 70, "Python", "Shin", quiz6);
    Classroom room7(80, 80, "Computer Architecture", "Paek", quiz7);
    Classroom room8(30, 19, "AI", "Kim", quiz8);
    Classroom room9(12, 20, "Automata", "Kim", quiz9);

    //view setting
    View gameView;


    //first map view
    map = gameView.startView();


    //movement
    int posX = 20;
    int posY = 16;
    gotoxy(posX, posY);
    cout << "��";

    //map���� ���� arr�� �޾Ƽ� ������ ���� ��ġ�� �ش� �迭���� posX�� posY ���� 1���� Ȯ���ϰ� 1�̸� ����..
    //���� ��ġ�� �Ѿ�� ȭ���� �� �ٲ��
    while (1)
    {
        if (_kbhit())   // Ű���� �Է� ������ 1��ȯ 
        {
            //
            // ���� ���� ����
            //
            gotoxy(posX, posY);
            printf("  "); // ĳ���� �����

            // Ű �Է� ó�� �� ����
            switch (_getch())
            {
            case LEFT:
                // ĳ���Ͱ� ���� ����� �ʵ��� ����ó��
                if (map[posY][posX / 2 - 1] == 1)
                    break;
                if (map[posY][posX / 2 - 1] == 11) //�л� ���� ó��
                    break;

                //������ ���� ó��
                if (map[posY][posX / 2 - 1] == 12) {
                    meetProf = true;
                }

                posX -= 2;
                break;

            case RIGHT:
                if (map[posY][posX / 2 + 1] == 1)
                    break;
                if (map[posY][posX / 2 + 1] == 11) //�л� ���� ó��
                    break;

                //������ ���� ó��
                if (map[posY][posX / 2 + 1] == 12) {
                    meetProf = true;
                }

                posX += 2;
                break;

            case UP:
                if (map[posY - 1][posX / 2] == 1)
                    break;
                if (map[posY - 1][posX / 2] == 11) //�л� ���� ó��
                    break;

                //door ó��

                if (map[posY - 1][posX / 2] != 1 && map[posY - 1][posX / 2] != 0 && map[posY - 1][posX / 2] <= 10) {
                    roomNum = map[posY - 1][posX / 2];
                }
                //������ ���� ó��
                if (map[posY - 1][posX / 2] == 12) {
                    meetProf = true;
                }

                posY--;
                break;

            case DOWN:
                if (posY >= 16)
                    break;
                if (map[posY + 1][posX / 2] == 1)
                    break;
                if (map[posY + 1][posX / 2] == 11) //�л� ���� ó��
                    break;

                //door ó��
                if (map[posY + 1][posX / 2] != 1 && map[posY + 1][posX / 2] != 0 && map[posY - 1][posX / 2] <= 10) {
                    roomNum = map[posY + 1][posX / 2];
                }
                //������ ���� ó��
                if (map[posY + 1][posX / 2] == 12) {
                    meetProf = true;
                }


                posY++;
                break;
            }

            // ���ο� ��ǥ(�̵���ġ)�� ĳ���� �׸���
            gotoxy(posX, posY);
            printf("��");

            //classroom enter
            if (roomNum != -1) {

                gotoxy(posX, posY);
                printf("  ");

                //roomNum-1�� ���ȣ 
                if (roomNum == 2) { //1�� ��
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room1);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;

                }
                else if (roomNum == 3) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room2);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 4) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room3);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 5) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room4);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 6) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room5);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 7) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room6);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 8) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room7);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 9) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room8);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 10) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room9);
                    gotoxy(posX, posY);
                    printf("��");
                    room = roomNum;
                    roomNum = -1;
                }


            }


            if (meetProf == true) {
                system("cls");
                //clrscr();
                Classroom tmp_room;

                if (room == 2) {
                    tmp_room = room1;
                }
                else if (room == 3) {
                    tmp_room = room2;
                }
                else if (room == 4) {
                    tmp_room = room3;
                }
                else if (room == 5) {
                    tmp_room = room4;
                }
                else if (room == 6) {
                    tmp_room = room5;
                }
                else if (room == 7) {
                    tmp_room = room6;
                }
                else if (room == 8) {
                    tmp_room = room7;
                }
                else if (room == 9) {
                    tmp_room = room8;
                }
                else if (room == 10) {
                    tmp_room = room9;
                }

                try_answer = gameView.quizView(tmp_room);
                Quiz this_quiz = tmp_room.class_quiz;
                correctness = this_quiz.checkCorrect(try_answer);

                if (correctness) {
                    cout << endl;
                    cout << "                correct" << endl;
                    meetProf = false;
                }
                else { //wrong�� ����� view
                    cout << "                wrong" << endl;
                    meetProf = false;
                }


                if (room == 2) { //correct�� ����� view


                    cout << "                You find OOP class!!" << endl;
                    cout << "                Class name : " << tmp_room.class_name << endl;
                    cout << "                Professor : " << tmp_room.professor << endl;
                    cout << "                Student number : " << tmp_room.student_num << endl;

                    cout << "                =====CLEAR=====" << endl;

                    //�帧�� ���� map ����
                    Sleep(3000);
                    system("cls");
                    //clrscr();
                }

                else {
                    cout << "                It's not OOP class!!" << endl;
                    cout << "                Try agin, find OOP class" << endl;
                    Sleep(3000);
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.startView();
                    gotoxy(posX, posY);
                    printf("��");
                }
            }
        }
    }

}

