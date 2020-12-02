#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string.h>

using namespace std;

class Burger {
private:
	const char * name;
	const char * whoLikeThis;
	const char * recipe;
public:
	Burger() {

	}

	Burger(const char* _recipe) {
		_recipe = recipe;
	}

	Burger(const char* _name, const char* _recipe) {
		name = _name;
		_recipe = recipe;
	}

	const char* getRecipe() {
		return recipe;
	}

	const char* getNmae() {
		return name;
	}
		
	const char* getWhoLikeThis() {
		return whoLikeThis;
	}
};

class Freshman {
private:
	const char* name;
	Burger FavoriteBurger;
public:
	Freshman() {

	}

	Freshman(const char* _name, Burger _FavoriteBurger) {
		name = _name;
		FavoriteBurger = _FavoriteBurger;
	}

	bool isLikeThis(Burger _burger) {
		if (_burger.getRecipe() == FavoriteBurger.getRecipe())
			return true;
		else
			return false;
	}

	const char* getName() {
		return name;
	}

	Burger getBurger() {
		return FavoriteBurger;
	}
};

class Senior {
private:
	vector<char> makedBurger;
public:
	Senior() {

	}

	void CleanUp() {
		makedBurger.clear();
	}
	
	void stackBurger(char ingredient) {
		makedBurger.push_back(ingredient);
	}

	vector<char> getBurger() {
		return makedBurger;
	}
};

class Ingredient {
private:
	const char* name;
	char ingredient;

public:
	Ingredient(const char* _name, char _ingredient) {
		name = _name;
		ingredient = _ingredient;
	}

	const char* getName() {
		return name;
	}

	char getIngredient() {
		return ingredient;
	}
};

class IngredientSelector{
private:
	int nowIndex = 0;
	int maxIndex;
	vector<Ingredient> Ingredients;
public:
	IngredientSelector(vector<Ingredient> List) {
		Ingredients = List;
		maxIndex = List.size() - 1;
	}

	void leftIndex() {
		if (nowIndex > 0)
			nowIndex -= 1;
	}

	void rightIndex() {
		if(nowIndex < maxIndex)
			nowIndex += 1;
	}

	Ingredient getNowIngredient() {
		return Ingredients[nowIndex];
	}

	vector<Ingredient> getIngredients() {
		return Ingredients;
	}

	int getIndex() {
		return nowIndex;
	}
};

class GameDisplay{
public:
	void init() {
		system("mode con cols=100 lines=25 | title CAU_BURGER"); // 콘솔창 크기 및 제목 설정
		CursorView(0);

		const char* initPanel[] = {
			"########################################",
			"#                                      #",
			"#             'CAU BURGER'             #",
			"#                                      #",
			"#       You must satisfiy freshman     #",
			"#          by making hamburger         #",
			"#                                      #",
			"#            [Press Any key]           #",
			"#                                      #",
			"########################################"
		};
		for (int i = 0; i < 10; i++) {
			gotoxy(29, 7 + i);
			printf("%s", initPanel[i]);
		}
		for(int i=0; (!_kbhit()); i++) {
			gotoxy(29, 14);
			if (i % 2 == 0)
				printf("#            [Press Any key]           #");
			else
				printf("#                                      #");
			Sleep(400);
		}
		system("cls");
	}

	void gotoxy(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void CursorView(char show)//커서숨기기
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = show;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	void drawSelector(IngredientSelector selector) {
		vector<Ingredient> ingredients = selector.getIngredients();
		char selectorbar[3][100];
		strcpy(selectorbar[0], "┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐");
		strcpy(selectorbar[1], "│   │   │   │   │   │   │   │   │   │   │   │   │");
		strcpy(selectorbar[2], "└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘");
		
		strncpy(selectorbar[0] + selector.getIndex() * 8, "┏━━━┓", sizeof("┏━━━┓") - 1);
		strncpy(selectorbar[1] + selector.getIndex() * 5, "┃   ┃", sizeof("┃   ┃") - 1);
		strncpy(selectorbar[2] + selector.getIndex() * 8, "┗━━━┛", sizeof("┗━━━┛") - 1);
		
		for (int i = 0; i < 12; i++)
			selectorbar[1][3 + 5 * i] = ingredients[i].getIngredient();


		gotoxy(0, 19);
		for (int i = 0; i < 100; i++) printf(" ");
		const char* ingredientName = selector.getNowIngredient().getName();
		gotoxy(50 - strlen(ingredientName) / 2 - 1, 19);
		printf("%s", ingredientName);


		for (int i = 0; i < 3; i++) {
			gotoxy(25, 21 + i);
			printf("%s\n", selectorbar[i]);
		}
	}

	void drawBurger(vector<char> Burger) {
		for (int i = 0; i < Burger.size(); i++) {
			gotoxy(50 - 10, 16 - i);
			for (int j = 0; j < 20; j++)
				printf("%c", Burger[i]);
		}
	}

	void drawFreshman(Freshman freshman) {
		gotoxy(10, 10);
		printf("%s", freshman.getName());
		gotoxy(10, 11);
		printf("%s", freshman.getBurger().getNmae());

		const char* recipe = freshman.getBurger().getRecipe();
		for (int i = 0; i < strlen(recipe); i++) {
			printf("s");
			gotoxy(10, 13 + i);
			for (int j = 0; j < 3; j++) {
				printf("%c", recipe[i]);
			}
		}
	}
};