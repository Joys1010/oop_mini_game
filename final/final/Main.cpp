#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

	for (int i = 1; i <= 6; i++) {
		total_manager.game_loadingScreen(i, total_exp, total_manager.player.getName());
		total_exp += total_manager.game_playScreen(i);
		system("cls");
	}

	total_manager.player.setExp(total_exp);
	total_manager.game_endScreen(total_manager.player);

	return 0;
}