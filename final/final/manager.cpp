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

void Manager::CursorView(char show)//커서숨기기
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
			cout << "                                                              경험치: " << exp << "                    " << endl;
			cout << "                                             <STAGE1>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                     코로나 시국이 끝나고 오랜만에 학교에 등교한 "<<name<< "는 310관 6층        " << endl;
			cout << "                    사물함에 있는 전공책을 꺼내 엘레베이터를 타고 올라가려합니다.       " << endl;
			cout << "                  하지만 도통 어느 사물함에 OOP 전공책이 있는지 기억이 나지 않는 "<<name<<",    " << endl;
			cout << "                    제한 시간 안에 OOP 전공책을 찾고, 엘레베이터를 타러 가세요!        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <조작방법>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                 위: w, 아래: s, 왼쪽: a, 오른쪽: d                 " << endl;
			cout << "                           장애물이나 벽이 부딪히면 원래 위치로 돌아갑니다.            " << endl;
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
			cout << "                                                              경험치: " << exp << "                    " << endl;
			cout << "                                             <STAGE2>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                      엘리베이터에서 "<<name<<" 는 솦새내기들 4명을 만났습니다.        " << endl;
			cout << "                   "<<name<<"는 새내기들을 인사만하고 보내기 좀그래서 가는 길에 있는       " << endl;
			cout << "                       CAU BURGER를 사주려고합니다! 지하 4층 CAU BURGER에서      " << endl;
			cout << "                    각 새내기들이 좋아하는 버거에 맞게 버거 재료들을 조합해주세요.       " << endl;
			cout << "                         게임을 완료해 새내기들의 배를 만족시켜주세요!                      " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <조작방법>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                      / ◀ : 왼쪽 / ▶ : 오른쪽 / ENTER : 재료선택 / L : 버거완성                 " << endl;
			cout << "                     버거를  잘못 만들면은 목숨을 한 개 잃으며 다시 만들어야합니다.            " << endl;
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
			cout << "                                                              경험치: " << exp << " " << endl;
			cout << "                                             <STAGE3>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                  어쩌다 후배를 만나 후배에게 CAU BURGER를 소개해줄 겸 햄버거를 사주고        " << endl;
			cout << "                        시계를 보니 강의 시작 시간이 5분밖에 남지 않았는데..       " << endl;
			cout << "                                  얼른 310관 엘레베이터로 뛰어가자!     " << endl;
			cout << "                        30초안에 장애물을 피하면서 엘레베이터를 타러가세요!         " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <조작방법>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                        / 스페이스키 : 점프 /                " << endl;
			cout << "                              장애물에 부딪히면 목숨 하나를 잃게 됩니다.             " << endl;
			cout << "                                  목숨을 다 잃으면 지각하게 됩니다.                  " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 4) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              경험치: " << exp << "" << endl;
			cout << "                                             <STAGE4>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                         OOP 교실을 찾아라        " << endl;
			cout << "                             각 교실을 방문하며 ▣로 표현된 교수님이 내주는       " << endl;
			cout << "                              퀴즈를 맞추고 최종적으로 OOP 교실을 찾아라!    " << endl;
			cout << "                          " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <조작방법>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                           방향키, 벽인 ▨와 학생인 ◆를 피하여 움직이세요.   " << endl;
			cout << "                                 각 교실의 문은 □로 표현되었습니다                        " << endl;
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
			cout << "                                                              경험치: " << exp << "                    " << endl;
			cout << "                                             <STAGE5>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                    오늘은 팝 퀴즈를 보는 날입니다. 그런데 "<<name<<"은 깜박하고 쪽지시험을       " << endl;
			cout << "                         준비하지 않았습니다! 그래서 몰래 수업을 나오려는 도중......      " << endl;
			cout << "                     가방 지퍼를 닫지 않아 가방에 있던 물건이 우수수 쏟아집니다    " << endl;
			cout << "                          \"쿠당당!!......\"소리가 강의실에 크게 울렸고, " << endl;
			cout << "                                화가난 TA ♨가 당신 ◎을 쫓아옵니다!        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <조작방법>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                            방향키, space                " << endl;
			cout << "                             쏟아진 아이템들 중 진짜 아이템을 찾아야합니다.            " << endl;
			cout << "                               space 바: 바나나 <<< 아이템 사용(♨ 방해)              " << endl;
			cout << "                                           [Press Any key]                        " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
		}
		else if (stage == 6) {
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                ##################################################################" << endl;
			cout << "                                                              경험치: "<<exp<<"    " << endl;
			cout << "                                             <STAGE6>                             " << endl;
			cout << "                                                                                  " << endl;
			cout << "                    교수님과의 추격전을 마치고 수업을 빠져나오니, 배가 출출해졌습니다.        " << endl;
			cout << "                        동기들과 슈퍼피자를 시켜 먹으려 과방으로 향하는 "<<name<<"       " << endl;
			cout << "                  하지만 과방을 사용하려면, 소프트웨어 학부 학생임을 인증해야 합니다.    " << endl;
			cout << "                        게임을 완료해 소프트웨어 학부 학생임을 인증하세요!       " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                                                                  " << endl;
			cout << "                                             <조작방법>                            " << endl;
			cout << "                                                                                  " << endl;
			cout << "                            ▲  : UP / ▼ : DOWN / ◀ : LEFT / ▶ : RIGHT                 " << endl;
			cout << "                                     레벨 2까지 완료해야합니다!            " << endl;
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
