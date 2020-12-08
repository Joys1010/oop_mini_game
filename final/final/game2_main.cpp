#include "game2_BURGER.cpp"

#define LEFT  75      // ��������Ű 
#define RIGHT 77      // ��������Ű 
#define ENTER 13      // ����Ű

class MiniGame2 {
private:
    /* Init */
    int life = 5;
    //Game Display Initialize
    GameDisplay display = GameDisplay();

    Ingredient bread = Ingredient("��", '$');
    Ingredient cheese = Ingredient("ġ��", '-');
    Ingredient source = Ingredient("�ҽ�", '~');
    Ingredient pickle = Ingredient("��Ŭ", '>');
    Ingredient onion = Ingredient("����", '*');
    Ingredient cowPatty = Ingredient("�Ұ�� ��Ƽ", '#');
    Ingredient lettuce = Ingredient("�����", '/');
    Ingredient tomato = Ingredient("�丶��", '@');
    Ingredient hashbrown = Ingredient("�ؽ�����", '+');
    Ingredient bulgogiPatty = Ingredient("�Ұ�� ��Ƽ", '=');
    Ingredient chickenPatty = Ingredient("ġŲ ��Ƽ", '&');
    Ingredient shrimpPatty = Ingredient("���� ��Ƽ", '%');

    vector<Ingredient> burgerIngredients = {
       bread, cheese, source,
       pickle, onion, cowPatty,
       lettuce, tomato, hashbrown,
       bulgogiPatty, chickenPatty, shrimpPatty
    };

    //Ingredient Selector Initialize
    IngredientSelector selector = IngredientSelector(burgerIngredients);

    //Burgers Initialize
    vector<Ingredient> doubleCheeseBurgerRecipe = { bread, cowPatty, cheese, cowPatty, cheese, source, lettuce, bread };
    vector<Ingredient> shrimpBurgerRecipe = { bread, shrimpPatty, source, lettuce,  bread };
    vector<Ingredient> jinjeoChickenBurgerRecipe = { bread, chickenPatty, tomato, lettuce, source, bread };
    vector<Ingredient> HashBrownCheeseBurgerRecipe = { bread, cowPatty, cheese, cowPatty, cheese, source, lettuce, hashbrown, bread };

    Burger doubleCheeseBurger = Burger("����ġ�����", doubleCheeseBurgerRecipe);
    Burger shrimpBurger = Burger("�������", shrimpBurgerRecipe);
    Burger jinjeoChickenBurger = Burger("����ġŲ����", jinjeoChickenBurgerRecipe);
    Burger HashBrownCheeseBurger = Burger("����ġ����ſ� �ؽ�����", doubleCheeseBurgerRecipe);

    //Freshmans Initialize
    vector<Freshman> freshmans = {
       Freshman("����", doubleCheeseBurger), Freshman("����", shrimpBurger),
       Freshman("����", jinjeoChickenBurger), Freshman("ȿâ", HashBrownCheeseBurger)
    };

    //Senior Initialize
    Senior LimGeon = Senior();
public:
    int start() {
        /* Process */
        for (int i = 0; i < 4; i++) {
            system("cls");
            int nextFreshman = 0;
            while (1) {
                display.drawSelector(selector);
                display.drawBurger(LimGeon.getBurger());
                display.drawFreshman(freshmans[i]);
                char key = _getch();
                switch (key) {
                case LEFT:
                    selector.leftIndex();
                    break;
                case RIGHT:
                    selector.rightIndex();
                    break;
                case ENTER:
                    LimGeon.stackBurger(selector.getNowIngredient().getIngredient());
                    break;
                case 'l':
                    nextFreshman = freshmans[i].isLikeThis(LimGeon.getBurger());
                    system("cls");
                    if (nextFreshman == 1) {
                        display.drawVictory(life);
                    }
                    else if (nextFreshman == 2) {
                        if (life > 0)
                            life -= 1;
                        display.drawDefeat(life);
                        i--;
                    }
                    LimGeon.CleanUp();
                    Sleep(2200);
                    break;
                default:
                    break;
                }
                if (nextFreshman == 1 || nextFreshman == 2)
                    break;
            }
        }
        _getch();
        _getch();
        return life;
    }
};

