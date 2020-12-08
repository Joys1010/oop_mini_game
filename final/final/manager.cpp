#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include "manager.h"
#include "game1.h"
#include "game2_main.cpp"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"


vector <string> Manager::game_startScreen() {
	system("mode con cols=100 lines=25 | title CAU MINI GAME");
	string name;
	string id;
	string dept;
	vector <string> info;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                     ====================================================" << endl;
	cout << "                           #####  #####  #####  #####  #####  #####" << endl;
	cout << "                           #      #      #      #   #  #   #  #" << endl;
	cout << "                           ####   #####  #      #####  #####  ####" << endl;
	cout << "                           #          #  #      #   #  #      #" << endl;
	cout << "                           #####  #####  #####  #   #  #      #####" << endl;
	cout << endl;
	cout << "                                  #####  #####  #####  #####" << endl;
	cout << "                                  #      #   #  #        #  " << endl;
	cout << "                                  #####  #   #  ####     #  " << endl;
	cout << "                                      #  #   #  #        #  " << endl;
	cout << "                                  #####  #####  #        #    ##" << endl;
	cout << "                     ====================================================" << endl;
	cout << "                                          < TEAM 4 >" << endl;
	cout << endl;
	cout << "                                  Please enter your name : ";
	cin >> name;
	cout << "                                   Please enter your ID : ";
	cin >> id;
	cout << "                             Please enter your department name : ";
	cin >> dept;

	info.push_back(name);
	info.push_back(id);
	info.push_back(dept);

	return info;
}

int Manager::lifeToExp(int life) {
	int exp=0;
	if (life > 0) {
		exp = life * 10;
	}
	return exp;
}

int Manager::game_playScreen(int stage) {
	int life = 0;
	switch (stage) {
	case 1:
	{
		Game1 title;
		title.init();
		life = title.gLoop(0);
		break;
	}
	case 2:
	{
		MiniGame2 miniGame2 = MiniGame2();
		life = miniGame2.start();
		break;
	}
	case 3:
	{
		Game3 test;
		life = test.display();
		break;
	}
	case 4:
	{
		Manager4 game4_manager;
		life = game4_manager.managing();
		break;
	}
	case 5:
	{
		Game5 test2;
		life = test2.life();
		break;
	}
	case 6:
	{
		Game6 test1;
		life = test1.game6();
		break;
	}
	default:
		break;
	};
	return lifeToExp(life);
}

void Manager::CursorView(char show)//Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Manager::game_loadingScreen(int stage, int exp, string name) {
		CursorView(0);
		if (stage == 1) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              ����ġ: " << exp << "                    " << endl;
			cout << "                                             <STAGE1>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                     �ڷγ� �ñ��� ������ �������� �б��� ��� "<<name<< "�� 310�� 6��        " << endl;
			cout << "                    �繰�Կ� �ִ� ����å�� ���� ���������͸� Ÿ�� �ö󰡷��մϴ�.       " << endl;
			cout << "                  ������ ���� ��� �繰�Կ� OOP ����å�� �ִ��� ����� ���� �ʴ� "<<name<<",    " << endl;
			cout << "                    ���� �ð� �ȿ� OOP ����å�� ã��, ���������͸� Ÿ�� ������!        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <���۹��>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                 ��: w, �Ʒ�: s, ����: a, ������: d                 " << endl;
			cout << "                           ��ֹ��̳� ���� �ε����� ���� ��ġ�� ���ư��ϴ�.            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 2) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              ����ġ: " << exp << "                    " << endl;
			cout << "                                             <STAGE2>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                      ���������Ϳ��� "<<name<<" �� ��������� 4���� �������ϴ�.        " << endl;
			cout << "                   "<<name<<"�� ��������� �λ縸�ϰ� ������ ���׷��� ���� �濡 �ִ�       " << endl;
			cout << "                       CAU BURGER�� ���ַ����մϴ�! ���� 4�� CAU BURGER����      " << endl;
			cout << "                    �� ��������� �����ϴ� ���ſ� �°� ���� ������ �������ּ���.       " << endl;
			cout << "                         ������ �Ϸ��� ��������� �踦 ���������ּ���!                      " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <���۹��>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                      / �� : ���� / �� : ������ / ENTER : ��ἱ�� / L : ���ſϼ�                 " << endl;
			cout << "                     ���Ÿ�  �߸� ������� ����� �� �� ������ �ٽ� �������մϴ�.            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 3) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              ����ġ: " << exp << " " << endl;
			cout << "                                             <STAGE3>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                  ��¼�� �Ĺ踦 ���� �Ĺ迡�� CAU BURGER�� �Ұ����� �� �ܹ��Ÿ� ���ְ�        " << endl;
			cout << "                        �ð踦 ���� ���� ���� �ð��� 5�йۿ� ���� �ʾҴµ�..       " << endl;
			cout << "                                  �� 310�� ���������ͷ� �پ��!     " << endl;
			cout << "                        30�ʾȿ� ��ֹ��� ���ϸ鼭 ���������͸� Ÿ��������!         " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <���۹��>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                        / �����̽�Ű : ���� /                " << endl;
			cout << "                              ��ֹ��� �ε����� ��� �ϳ��� �Ұ� �˴ϴ�.             " << endl;
			cout << "                                  ����� �� ������ �����ϰ� �˴ϴ�.                  " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 4) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              ����ġ: " << exp << "" << endl;
			cout << "                                             <STAGE4>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                         OOP ������ ã�ƶ�        " << endl;
			cout << "                             �� ������ �湮�ϸ� �÷� ǥ���� �������� ���ִ�       " << endl;
			cout << "                              ��� ���߰� ���������� OOP ������ ã�ƶ�!    " << endl;
			cout << "                          " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <���۹��>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                           ����Ű, ���� �ɿ� �л��� �߸� ���Ͽ� �����̼���.   " << endl;
			cout << "                                 �� ������ ���� ��� ǥ���Ǿ����ϴ�                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 5) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              ����ġ: " << exp << "                    " << endl;
			cout << "                                             <STAGE5>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                    ������ �� ��� ���� ���Դϴ�. �׷��� "<<name<<"�� �����ϰ� ����������       " << endl;
			cout << "                         �غ����� �ʾҽ��ϴ�! �׷��� ���� ������ �������� ����......      " << endl;
			cout << "                     ���� ���۸� ���� �ʾ� ���濡 �ִ� ������ ����� ������ϴ�    " << endl;
			cout << "                          \"����!!......\"�Ҹ��� ���ǽǿ� ũ�� ��Ȱ�, " << endl;
			cout << "                                ȭ���� TA �Ͱ� ��� ���� �Ѿƿɴϴ�!        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <���۹��>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                            ����Ű, space                " << endl;
			cout << "                             ����� �����۵� �� ��¥ �������� ã�ƾ��մϴ�.            " << endl;
			cout << "                               space ��: �ٳ��� <<< ������ ���(�� ����)              " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 6) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              ����ġ: "<<exp<<"    " << endl;
			cout << "                                             <STAGE6>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                    �����԰��� �߰����� ��ġ�� ������ ����������, �谡 �����������ϴ�.        " << endl;
			cout << "                        ������ �������ڸ� ���� ������ �������� ���ϴ� "<<name<<"       " << endl;
			cout << "                  ������ ������ ����Ϸ���, ����Ʈ���� �к� �л����� �����ؾ� �մϴ�.    " << endl;
			cout << "                        ������ �Ϸ��� ����Ʈ���� �к� �л����� �����ϼ���!       " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <���۹��>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                            ��  : UP / �� : DOWN / �� : LEFT / �� : RIGHT                 " << endl;
			cout << "                                     ���� 2���� �Ϸ��ؾ��մϴ�!            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}

		
		for (int i = 0; (!_kbhit()); i++) {
			gotoxy(29, 18);
			if (i % 2 == 0)
				printf("             [Press Any key]            ");
			else
				printf("                                        ");
			Sleep(400);
		}
		system("cls");
}

void Manager::game_endScreen(Player player) {

	cout << "                              ====================================================" << endl;
	cout << "                                    #####  #####  #####  #####  #####  #####" << endl;
	cout << "                                    #      #      #      #   #  #   #  #" << endl;
	cout << "                                    ####   #####  #      #####  #####  ####" << endl;
	cout << "                                    #          #  #      #   #  #      #" << endl;
	cout << "                                    #####  #####  #####  #   #  #      #####" << endl;
	cout << endl;
	cout << "                                           #####  #####  #####  #####" << endl;
	cout << "                                           #      #   #  #        #  " << endl;
	cout << "                                           #####  #   #  ####     #  " << endl;
	cout << "                                               #  #   #  #        #  " << endl;
	cout << "                                           #####  #####  #        #    ##" << endl;
	cout << "                              ====================================================" << endl;
	cout << "                                                   < TEAM 4 >" << endl;
	cout << endl;
	cout << "                                            Player name : " << player.getName() << endl;
	cout << "                                              Player ID : " << player.getID() << endl;
	cout << "                                        Player department name : " << player.getDepartment() << endl;
	cout << "                                            Player EXP : " << player.getExp()<< endl;
	cout << endl;

	if (player.getExp() == 300) { //5*6*10
		cout << "                                          You are the BEST!!!" << endl;
	}
	else if (player.getExp() > 250) {
		cout << "                                          You did a great job!!!" << endl;
	}
	else if (player.getExp() > 200) {
		cout << "                                          You did a good job!!!" << endl;
	}
	else if (player.getExp() > 150) {
		cout << "                                          You did a nice job!!!" << endl;
	}
	else if (player.getExp() > 100) {
		cout << "                           Little bit disappointing... How about trying again?" << endl;
	}
	else if (player.getExp() > 50) {
		cout << "                                   Disappointing..... You can try again" << endl;
	}
	else if (player.getExp() > 0) {
		cout << "                               Your EXP is really bad. You must try again." << endl;
	}
	









}
