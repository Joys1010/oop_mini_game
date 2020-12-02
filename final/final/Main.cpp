#include <iostream>
#include "game1.h"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"


int main()
{							//로딩화면에 포함될 내용 -> 게임 방법, 스토리 진행 상황 
	Game1 title;			//매니저가 이 게임 오브젝트를 관리하면서 순서대로 display하는 역할 
	title.init();			//player를 만들고 각 game의 life에 따라 경험치 계산 -> 매니저
	title.gLoop(0);			//게임 사이 사이의 로딩 창 만들기-> 매니저
							//시작, 엔딩 화면 띄우기 -> 매니저
	system("cls");			//시작화면엔 전체적인 게임시작
							//엔딩 화면 경험치에 따라 멘트 출력
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