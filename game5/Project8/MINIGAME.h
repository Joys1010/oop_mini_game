#pragma once
#include "Scene.h"
#include<iostream>
#include<conio.h>
using namespace std;


class Game : public Scene {

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

	int MAPX;
	int MAPY;
	double PI;
	int NUM_OF_ITEM;

	//comment 클래스
	string comment[5];

public:
	Game();
	~Game();
	void Update();
	void GameScreen();
	void Draw();
	int succeed();
	int hitby(Char player, Char boss);
	int hitby(Item itemA, Char charA);
	void gLoop(int mapCode);

};

