#include <iostream>
#include <utility>
#include <windows.h>
#include <Windows.h>
#include <conio.h>

#include "game4_manager.h"

#define LEFT 75        // 방향키 왼쪽
#define RIGHT 77    // 방향키 오른쪽
#define UP 72        // 방향키 위
#define DOWN 80        // 방향키 아래

void gotoxy2(int x, int y) {
    
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Manager4::managing() {

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);


    //variable setting
    int roomNum = -1;
    int room = -1;
    vector <vector <int>> map;
    string try_answer;
    bool correctness = false;
    bool meetProf = false;

    
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

    quiz1.question = "How many credits do I need to take in my major to graduate from our department?";
    quiz1.answer = "84";

    quiz2.question = "Which of the following is not required 전공 필수) for our major? \n 1. Algorithm 2. OOP 3. Data Structure 4. Computer Architecture";
    quiz2.answer = "2";

    quiz3.question = "What programming language do you use in your OOP class?";
    quiz3.answer = "C++";

    quiz4.question = "Which college does our department belong to?";
    quiz4.answer = "Software";

    quiz5.question = "In which building is the department office of our department?";
    quiz5.answer = "310";

    quiz6.question = "What is the largest building in our school?";
    quiz6.answer = "310";

    quiz7.question = "When is our school's opening anniversary? (format example :  1/1)";
    quiz7.answer = "10/11";

    quiz8.question = "Which of the following buildings does not have a student cafeteria? \n 1. 310 2. 208 3. 308 4. 303";
    quiz8.answer = "2";

    quiz9.question = "Which building is the PC room of our department?";
    quiz9.answer = "208";


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
    View4 gameView;


    //first map view
    map = gameView.startView();

    int life = 5;


    //movement
    int posX = 20;
    int posY = 16;
    gotoxy2(posX, posY);
    cout << "★";

    //map에서 벽의 arr을 받아서 움직인 별의 위치가 해당 배열에서 posX와 posY 값이 1인지 확인하고 1이면 못감..
    //문의 위치를 넘어가면 화면이 슉 바뀌도록
    while (1)
    {
        gotoxy2(0, 0);
        cout << "life : " << life << endl;
        if (_kbhit())   // 키보드 입력 들어오면 1반환 
        {
            //
            // 기존 정보 정리
            //
            gotoxy2(posX, posY);
            printf("  "); // 캐릭터 지우기

            // 키 입력 처리 및 갱신
            switch (_getch())
            {
            case LEFT:
                // 캐릭터가 벽을 벗어나지 않도록 예외처리
                if (map[posY][posX / 2 - 1] == 1)
                    break;
                if (map[posY][posX / 2 - 1] == 11) //학생 만남 처리
                    break;

                //교수님 만남 처리
                if (map[posY][posX / 2 - 1] == 12) {
                    meetProf = true;
                }

                posX -= 2;
                break;

            case RIGHT:
                if (map[posY][posX / 2 + 1] == 1)
                    break;
                if (map[posY][posX / 2 + 1] == 11) //학생 만남 처리
                    break;

                //교수님 만남 처리
                if (map[posY][posX / 2 + 1] == 12) {
                    meetProf = true;
                }

                posX += 2;
                break;

            case UP:
                if (map[posY - 1][posX / 2] == 1)
                    break;
                if (map[posY - 1][posX / 2] == 11) //학생 만남 처리
                    break;

                //door 처리

                if (map[posY - 1][posX / 2] != 1 && map[posY - 1][posX / 2] != 0 && map[posY - 1][posX / 2] <= 10) {
                    roomNum = map[posY - 1][posX / 2];
                }
                //교수님 만남 처리
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
                if (map[posY + 1][posX / 2] == 11) //학생 만남 처리
                    break;

                //door 처리
                if (map[posY + 1][posX / 2] != 1 && map[posY + 1][posX / 2] != 0 && map[posY - 1][posX / 2] <= 10) {
                    roomNum = map[posY + 1][posX / 2];
                }
                //교수님 만남 처리
                if (map[posY + 1][posX / 2] == 12) {
                    meetProf = true;
                }


                posY++;
                break;
            }

            // 새로운 좌표(이동위치)에 캐릭터 그리기
            gotoxy2(posX, posY);
            printf("★");

            //classroom enter
            if (roomNum != -1) {

                gotoxy2(posX, posY);
                printf("  ");

                //roomNum-1이 방번호 
                if (roomNum == 2) { //1번 방
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room1);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;

                }
                else if (roomNum == 3) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room2);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 4) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room3);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 5) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room4);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 6) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room5);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 7) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room6);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 8) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room7);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 9) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room8);
                    gotoxy2(posX, posY);
                    printf("★");
                    room = roomNum;
                    roomNum = -1;
                }
                else if (roomNum == 10) {
                    system("cls");
                    //clrscr();
                    posX = 20;
                    posY = 16;
                    map = gameView.classView(room9);
                    gotoxy2(posX, posY);
                    printf("★");
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
                    cout << "                 =====CORRECT=====" << endl;
                    meetProf = false;
                }
                else { //wrong인 경우의 view
                    life--;
                    cout << "\n                 =====WRONG=====" << endl;
                    meetProf = false;
                }


                if (room == 2 && correctness == TRUE) { //correct인 경우의 view
                      

                    cout << "           =====You find OOP class!!=====" << endl;
                    cout << "                Class name : " << tmp_room.class_name << endl;
                    cout << "                Professor : " << tmp_room.professor << endl;
                    cout << "                Student number : " << tmp_room.student_num << endl;

                    cout << "\n                  =====CLEAR=====" << endl;

                    //흐름에 따라서 map 변경
                    Sleep(3000);
                    //clrscr();
                    system("cls");
                    
                    return life;
                }

                else if (room != 2){
                    cout << "\n                It's not OOP class!!" << endl;
                    cout << "                Try agin, find OOP class" << endl;
                    Sleep(3000);
                    //clrscr();
                    system("cls");
                    posX = 20;
                    posY = 16;
                    map = gameView.startView();
                    gotoxy2(posX, posY);
                    printf("★");
                }
                else if (room == 2 && correctness == FALSE) {
                    cout << "\n                It's OOP class!!" << endl;
                    cout << "                Try agin, Pass the quiz " << endl;
                    Sleep(3000);
                    //clrscr();
                    system("cls");
                    posX = 20;
                    posY = 16;
                    map = gameView.startView();
                    gotoxy2(posX, posY);
                    printf("★");

                }
            }
        }
    }

}

