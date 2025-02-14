#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string.h>

using namespace std;

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

class Burger {
private:
    const char* name;
    vector<Ingredient> recipe;
public:
    Burger() {

    }

    Burger(vector<Ingredient> _recipe) {
        recipe = _recipe;
    }

    Burger(const char* _name, vector<Ingredient> _recipe) {
        name = _name;
        recipe = _recipe;
    }

    vector<Ingredient> getRecipe() {
        return recipe;
    }

    const char* getName() {
        return name;
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

    int isLikeThis(vector<char> makedBurgerRecipe) {
        vector<Ingredient> myBurgerRecipe = FavoriteBurger.getRecipe();
        if (myBurgerRecipe.size() != makedBurgerRecipe.size())
            return 2;
        else {
            for (int i = 0; i < myBurgerRecipe.size(); i++) {
                if (myBurgerRecipe[i].getIngredient() != makedBurgerRecipe[i])
                    return 2;
            }
            return 1;
        }
    }

    const char* getName() {
        return name;
    }

    Burger getBurger() {
        return FavoriteBurger;
    }
};

class IngredientSelector {
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
        if (nowIndex < maxIndex)
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

class GameDisplay {
public:

    void gotoxy(int x, int y)
    {
        COORD pos = { x,y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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


        gotoxy(0, 18);
        for (int i = 0; i < 100; i++) printf(" ");
        const char* ingredientName = selector.getNowIngredient().getName();
        gotoxy(50 - strlen(ingredientName) / 2 - 1, 18);
        printf("%s", ingredientName);


        for (int i = 0; i < 3; i++) {
            gotoxy(25, 20 + i);
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
        gotoxy(35, 3);
        printf("%s는 %s을 좋아한다.", freshman.getName(), freshman.getBurger().getName());
        vector<Ingredient> recipe = freshman.getBurger().getRecipe();
        gotoxy(4, 7);
        printf("-------레시피-------");
        for (int i = 0; i < recipe.size() + 1; i++) {
            gotoxy(4, 9 + i);
            if (i != recipe.size())
                printf("%d번째: %s", i + 1, recipe[i].getName());
            else
                printf("--------------------");
        }
    }

    void drawVictory(int life) {
        const char* initPanel[] = {
           "                                          ",
           " ######################################## ",
           " # the freshman really like this Burger # ",
           " #           life: ★★★★★            # ",
           " ######################################## ",
           "                                          "
        };
        for (int i = 0; i < 6; i++) {
            gotoxy(27, 6 + i);
            printf("%s", initPanel[i]);
        }
        for (int i = 0; i < 5 - life; i++) {
            gotoxy(54 - i * 2, 9);
            printf("☆");
        }
    }

    void drawDefeat(int life) {
        const char* initPanel[] = {
           "                                          ",
           " ######################################## ",
           " # the freshman doesn't like this Burger# ",
           " #           life: ★★★★★           # ",
           " ######################################## ",
           "                                          "
        };
        for (int i = 0; i < 6; i++) {
            gotoxy(27, 6 + i);
            printf("%s", initPanel[i]);
        }
        for (int i = 0; i < 5 - life; i++) {
            gotoxy(54 - i * 2, 9);
            printf("☆");
        }
    }
};