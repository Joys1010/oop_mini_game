#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "game1.h"
#include "game2_main.cpp"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"


int main()
{							
	Game1 title;			
	title.init();			
	title.gLoop(0);			
						
	system("cls");	
	
	MiniGame2 miniGame2 = MiniGame2();
	miniGame2.start();
	
	system("cls");

	Game3 test;
	test.display();

	system("cls");

	Manager game4_manager;
	game4_manager.managing();

	system("cls");

	Game5 test2;
	test2.gLoop(0);

	system("cls");

	Game6 test1;
	test1.game6();

	return 0;
}