#pragma once
#include "game5_Scene.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<time.h>
using namespace std;

class Game5 : public Scene {

private:

	struct Char {//_Char {

		string fig;
		//int HP;			//체력
		int nMoveX, nMoveY;	//이동 좌표
		double nDist;		//이동 거리
		clock_t MoveTime;	//이동 시간 간격
		clock_t OldTime;	//이전 이동 시간
		int color;
	};//Char;

	struct Item {//_Item {

		string fig;
		bool GET;			//소장 여부
		int nMoveX, nMoveY;	//위치
		bool TIMER;			//타이머를 켰는지 안켰는지
		clock_t NewTime;	//유지 시간 간격
		clock_t OldTime;	//이전 이동 시간
		int color;
	};// Item;

	Char boss;
	Item boss_comment;//게임 멘트

	Char player;
	Item banana;//바나나
	Item cau_burger[3]; //카우버거
	Item studentIDcard[3];//학생증
	Item book[3];//책

	int MAPX;	//맵의 크기 
	int MAPY;	//맵의 크기
	double PI;
	int NUM_OF_ITEM;	//아이템 개수

	//comment 클래스
	string comment[5];

public:
	Game5();
	~Game5();
	void Update(); //움직임 업데이트
	void GameScreen();//게임 스크린 그리기
	void Draw();//게임 스크린과 버퍼 지우기
	int succeed();//성공 여부 확인
	int hitby(Char player, Char boss); //충돌 확인
	int hitby(Item itemA, Char charA);
	void gLoop(int mapCode); //게임 play 
	int life(); //게임 play , life 적용

};

