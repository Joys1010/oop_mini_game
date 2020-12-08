#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "game1.h"
#include "game2_main.cpp"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"
#include "manager.h"


int main()
{			
	int exp=0;
	int total_exp = 0;

	Manager total_manager;

	vector <string> info;
	

	info = total_manager.game_startScreen();

	total_manager.player.setName(info[0]);
	total_manager.player.setID(info[1]);
	total_manager.player.setDept(info[2]);
	fflush(stdin);

	system("cls");

	Game1 title;			
	title.init();			
	exp = title.gLoop(0);				
	system("cls");	

	if (exp > 0) {
		total_exp += exp * 10;
	}
	
	MiniGame2 miniGame2 = MiniGame2();
	//exp = miniGame2.start();
	system("cls");

	//if (exp > 0) {
	//	total_exp += exp * 10;
	//}

	Game3 test;
	exp = test.display();
	system("cls");

	if (exp > 0) {
		total_exp += exp * 10;
	}

	Manager4 game4_manager;
	exp = game4_manager.managing();

	system("cls");

	if (exp > 0) {
		total_exp += exp * 10;

	}

	Game5 test2;
	exp = test2.life();
	system("cls");
	
	if (exp > 0) {
		total_exp += exp * 10;
	}
	
	Game6 test1;
	exp = test1.game6();
	system("cls");

	if (exp > 0) {
		total_exp += exp * 10;
	}


	total_manager.player.setExp(total_exp);
	total_manager.game_endScreen(total_manager.player);

	return 0;
}