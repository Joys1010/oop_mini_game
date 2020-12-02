#include "CAU_BURGER.cpp"

#define LEFT  75      // ��������Ű 
#define RIGHT 77      // ��������Ű 
#define ENTER 13      // ����Ű

int main(void) {

	/* Init */

	//Game Display Initialize
	GameDisplay display = GameDisplay();

	vector<Ingredient> burgerIngredients = {
		Ingredient("��",'$'), Ingredient("ġ��",'-'),Ingredient("�ҽ�",'~'),
		Ingredient("��Ŭ",'>'),Ingredient("����",'*'),Ingredient("�Ұ�� ��Ƽ",'#'),
		Ingredient("�����",'/'),Ingredient("�丶��",'@'),Ingredient("�ؽ�����",'+'),
		Ingredient("�Ұ�� ��Ƽ",'='),Ingredient("ġŲ ��Ƽ",'&'),Ingredient("���� ��Ƽ",'%')
	};

	//Ingredient Selector Initialize
	IngredientSelector selector = IngredientSelector(burgerIngredients);

	//Burgers Initialize
	Burger doubleCheeseBurger = Burger("����ġ�����", "$#-#-~/$");
	Burger ShrimpBurger = Burger("�������", "$%~/$");
	Burger jinjeoChickenBurger = Burger("����ġŲ����", "$&@/~$");
	Burger HashBrownCheeseBurger = Burger("����ġ����ſ� �ؽ�����", "$#-#-~/+$");

	//Freshmans Initialize
	vector<Freshman> freshmans = { 
		Freshman("����", doubleCheeseBurger), Freshman("����", ShrimpBurger),
		Freshman("����", jinjeoChickenBurger), Freshman("ȿâ", HashBrownCheeseBurger) 
	};

	//Senior Initialize
	Senior LimGeon = Senior();




	/* Process */
	display.init();
	while (char key = _getch()) {
		switch(key) {
		case LEFT:
			selector.leftIndex();
			break;
		case RIGHT:
			selector.rightIndex();
			break;
		case ENTER:
			LimGeon.stackBurger(selector.getNowIngredient().getIngredient());

		default:
			break;
		}
		display.drawSelector(selector);
		display.drawBurger(LimGeon.getBurger());
		display.drawFreshman(freshmans[0]);
	}

	_getch();
	_getch();
	return 0;
}