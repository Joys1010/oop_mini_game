#include "CAU_BURGER.cpp"

#define LEFT  75      // 좌측방향키 
#define RIGHT 77      // 우측방향키 
#define ENTER 13      // 엔터키

int main(void) {

	/* Init */

	//Game Display Initialize
	GameDisplay display = GameDisplay();

	vector<Ingredient> burgerIngredients = {
		Ingredient("빵",'$'), Ingredient("치즈",'-'),Ingredient("소스",'~'),
		Ingredient("피클",'>'),Ingredient("양파",'*'),Ingredient("소고기 패티",'#'),
		Ingredient("양상추",'/'),Ingredient("토마토",'@'),Ingredient("해쉬브라운",'+'),
		Ingredient("불고기 패티",'='),Ingredient("치킨 패티",'&'),Ingredient("새우 패티",'%')
	};

	//Ingredient Selector Initialize
	IngredientSelector selector = IngredientSelector(burgerIngredients);

	//Burgers Initialize
	Burger doubleCheeseBurger = Burger("더블치즈버거", "$#-#-~/$");
	Burger ShrimpBurger = Burger("새우버거", "$%~/$");
	Burger jinjeoChickenBurger = Burger("진저치킨버거", "$&@/~$");
	Burger HashBrownCheeseBurger = Burger("더블치즈버거에 해쉬브라운", "$#-#-~/+$");

	//Freshmans Initialize
	vector<Freshman> freshmans = { 
		Freshman("민주", doubleCheeseBurger), Freshman("설희", ShrimpBurger),
		Freshman("은서", jinjeoChickenBurger), Freshman("효창", HashBrownCheeseBurger) 
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