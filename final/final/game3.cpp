#define _CRT_SECURE_NO_WARNINGS

#include "game3.h"

#define PLAYER_BOTTOM_Y 12
#define OBSTACLE_BOTTOM_Y 20
#define OBSTACLE_BOTTOM_X 45

Game3::Game3()
{
	life = 5, gravity = 3, isJumping = false, isBottom = true, playerY = PLAYER_BOTTOM_Y, obstacleX = OBSTACLE_BOTTOM_X;
}

//콘솔 창을 만드는 함수
void Game3::SetConsoleView()
{
	system("mode con:cols=100 lines=25|title Going to EV");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	
}

//커서의 위치를 x, y로 이동하는 함수
void Game3::GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int Game3::GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//플레이어를 그리는 함수
void Game3::DrawPlayer(int playerY)
{
	GotoXY(0, playerY);
	static bool legFlag = true;
	cout<<"        $$$$$$$ \n";
	cout<<"       $$     $$\n";
	cout<<"        $$$$$$$\n";
	cout<<"          $$$\n";
	cout<<"        $$$$$$$\n";
	cout<<"         $$$$$\n";
	cout<<"          $$$\n";
	cout<<"        $     $ \n";
	cout<<"        $     $ \n";
	cout<<"        $     $ \n";
	cout<<"        $     $ \n";
	if (legFlag)
	{
		cout<<"        $     $$$ \n";
		legFlag = false;
	}
	else
	{
		cout<<"        $$$     $ \n";
		legFlag = true;
	}
}

//장애물을 그리는 함수
void Game3::DrawObstacle(int OBSTACLEX, int prob)
{
	switch (prob)
	{
	case 1:
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y);
		cout << "$$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 1);
		cout << "$           $";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 2);
		cout << "$$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 3);
		cout << "$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 4);
		cout << "$$";
		break;
	case 2:
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y);
		cout << "$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 1);
		cout << "$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 2);
		cout << "$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 3);
		cout << "          $$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 4);
		cout << "$$$$$$$$$$$$";
		break;
	case 3:
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y);
		cout << "     $$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 1);
		cout << "   $$   $$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 2);
		cout << "  $$$   $$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 3);
		cout << " $$$$   $$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 4);
		cout << "$$$$$   $$$$$";
		break;
	}
}


//게임오버 그려줌
void Game3::DrawGameOver()
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	cout<<"===========================";
	GotoXY(x, y + 1);
	cout<<"======G A M E O V E R======";
	GotoXY(x, y + 2);
	cout<<"===========================";
	GotoXY(x, y + 5);

	cout<<"\n\n\n\n\n\n\n\n\n";
	system("pause");
}

//충돌했으면 true, 아니면 false
bool Game3::isCollision(const int OBSTACLEX, const int playerY, const int life)
{
	//장애물의 X가 플레이어의 몸체쪽에 있을때,
	//플레이어의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	cout << "OBSTACLEX : " << OBSTACLEX << " playerY : " << playerY << " life : " << life; 

	if (OBSTACLEX <= 8 && OBSTACLEX >= 4 &&
		playerY > 8)
	{
		return true;
	}
	return false;
}

int Game3::display()
{

	SetConsoleView();

	while (true)		// 게임 루프
	{
	
		clock_t start, curr;	//점수 변수 초기화
		start = clock();		//시작시간 초기화

		random_device prob;
		mt19937 gen(prob());
		uniform_int_distribution<int> dis(1, 3);
		int check = dis(gen);

		while (true)	//한 판에 대한 루프
		{
			 
			//충돌체크 장애물과 x값과 플레이어의 y값으로 판단
			if (isCollision(obstacleX, playerY,life)) {
				life--;
				obstacleX = -10;
			}

			//스페이스키가 눌렸고, 바닥이 아닐때 점프
			if (GetKeyDown() == ' ' && isBottom)
			{
				isJumping = true;
				isBottom = false;
			}

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
			if (isJumping)
			{
				playerY -= gravity;
			}
			else
			{
				playerY += gravity;
			}

			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
			if (playerY >= PLAYER_BOTTOM_Y)
			{
				playerY = PLAYER_BOTTOM_Y;
				isBottom = true;
			}

			//나무가 왼쪽으로 (x음수) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
			obstacleX -= 3;
			if (obstacleX <= 0)
			{
				obstacleX = OBSTACLE_BOTTOM_X;
				check = dis(gen);
			}

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (playerY <= 3)
			{
				isJumping = false;
			}

			DrawPlayer(playerY);		//draw player
			DrawObstacle(obstacleX, check);
				
			curr = clock();			//현재시간 받아오기

			if (((curr - start) / CLOCKS_PER_SEC) >= 30 || life ==0) {	 //게임종료
				break;
			}
			
			Sleep(60);
			system("cls");	//clear		

		}
		DrawGameOver();
		break;
	}

	return life;
}