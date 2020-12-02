#pragma once
#include "Scene.h"
#include<iostream>
#include<conio.h>
using namespace std;


class Game : public Scene {

private:	
	
	struct Char {//_Char {

		string fig;
		//int HP;			//ü��
		int nMoveX, nMoveY;	//�̵� ��ǥ
		double nDist;		//�̵� �Ÿ�
		clock_t MoveTime;	//�̵� �ð� ����
		clock_t OldTime;	//���� �̵� �ð�
		int color;
	};//Char;

	struct Item {//_Item {

		string fig;
		bool GET;			//���� ����
		int nMoveX, nMoveY;	//��ġ
		bool TIMER;			//Ÿ�̸Ӹ� �״��� ���״���
		clock_t NewTime;	//���� �ð� ����
		clock_t OldTime;	//���� �̵� �ð�
		int color;
	};// Item;

	Char boss;
	Item boss_comment;//���� ��Ʈ

	Char player;
	Item banana;//�ٳ���
	Item cau_burger[3]; //ī�����
	Item studentIDcard[3];//�л���
	Item book[3];//å

	int MAPX;
	int MAPY;
	double PI;
	int NUM_OF_ITEM;

	//comment Ŭ����
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

