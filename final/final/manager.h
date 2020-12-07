#pragma once
#ifndef MANAGER_H													
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "game1.h"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"

		//�Ŵ����� �� ���� ������Ʈ�� �����ϸ鼭 ������� display�ϴ� ���� 
		//player�� ����� �� game�� life�� ���� ����ġ ��� -> �Ŵ���
		//���� ���� ������ �ε� â �����-> �Ŵ���
		//�ε�ȭ�鿡 ���Ե� ���� -> ���� ���, ���丮 ���� ��Ȳ 																	
		//����ȭ�鿣 ��ü���� ���ӽ���
		//���� ȭ�� ����ġ�� ���� ��Ʈ ���
		//����, ���� ȭ�� ���� -> �Ŵ���

class Player {
private:
	string name;
	string student_ID;
	string department;
	int exp;
public:
	Player() {

	};

	Player(string, string, string);
	void setExp(int Exp) { this->exp = Exp; }
	int getExp() { return this->exp; }
	string getName() { return this->name; }
	string getID() { return this->student_ID; }
	string getDepartment() { return this->department; }
	void setName(string name) { this->name = name; }
	void setID(string id) { this->student_ID = id; }
	void setDept(string dept) { this->department = dept; }

};

class Manager {

public:
	Manager() {

	};
	vector <string> game_startScreen();
	int game_playScreen1();
	int game_playScreen2();
	int game_playScreen3();
	int game_playScreen4();
	int game_playScreen5();
	int game_playScreen6();
	void game_loadingScreen();
	void game_endScreen(Player player);

	Player player;
};


#endif