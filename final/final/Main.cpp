#include <iostream>
#include "game1.h"
#include "game3.h"
#include "game4_manager.h"
#include "game5_minigame.h"
#include "game5_Scene.h"
#include "game6.h"


int main()
{							//�ε�ȭ�鿡 ���Ե� ���� -> ���� ���, ���丮 ���� ��Ȳ 
	Game1 title;			//�Ŵ����� �� ���� ������Ʈ�� �����ϸ鼭 ������� display�ϴ� ���� 
	title.init();			//player�� ����� �� game�� life�� ���� ����ġ ��� -> �Ŵ���
	title.gLoop(0);			//���� ���� ������ �ε� â �����-> �Ŵ���
							//����, ���� ȭ�� ���� -> �Ŵ���
	system("cls");			//����ȭ�鿣 ��ü���� ���ӽ���
							//���� ȭ�� ����ġ�� ���� ��Ʈ ���
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