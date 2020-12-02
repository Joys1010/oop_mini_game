#pragma once
#ifndef MANAGER_H													
#define MANAGER_H

#include <iostream>
#include <string>
#include "game1.h"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"

		//매니저가 이 게임 오브젝트를 관리하면서 순서대로 display하는 역할 
		//player를 만들고 각 game의 life에 따라 경험치 계산 -> 매니저
		//게임 사이 사이의 로딩 창 만들기-> 매니저
		//로딩화면에 포함될 내용 -> 게임 방법, 스토리 진행 상황 																	
		//시작화면엔 전체적인 게임시작
		//엔딩 화면 경험치에 따라 멘트 출력
		//시작, 엔딩 화면 띄우기 -> 매니저

class Manager {
private:
	Player player;
public:
	void game_startScreen();
	int game_playScreen1();
	int game_playScreen2();
	int game_playScreen3();
	int game_playScreen4();
	int game_playScreen5();
	int game_playScreen6();
	void game_loadingScreen();
	void game_endScreen();
};

class Player {
private:
	string name;
	string student_ID;
	string department;
	int exp;
public:
	Player(string, string, string);
	void setExp(int);
	int getExp();
	string getName();
	string getID();
	string getDepartment();
};
#endif