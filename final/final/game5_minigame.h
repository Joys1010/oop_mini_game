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

	int MAPX;	//���� ũ�� 
	int MAPY;	//���� ũ��
	double PI;
	int NUM_OF_ITEM;	//������ ����

	//comment Ŭ����
	string comment[5];

public:
	Game5();
	~Game5();
	void Update(); //������ ������Ʈ
	void GameScreen();//���� ��ũ�� �׸���
	void Draw();//���� ��ũ���� ���� �����
	int succeed();//���� ���� Ȯ��
	int hitby(Char player, Char boss); //�浹 Ȯ��
	int hitby(Item itemA, Char charA);
	void gLoop(int mapCode); //���� play 
	int life(); //���� play , life ����

};

