#include "CAU_BURGER.cpp"

#define LEFT  75      // 좌측방향키 
#define RIGHT 77      // 우측방향키 
#define ENTER 13      // 엔터키

class MiniGame2 {
private:
		/* Init */

		//Game Display Initialize
		GameDisplay display = GameDisplay();

		Ingredient bread = Ingredient("빵", '$');
		Ingredient cheese = Ingredient("치즈", '-');
		Ingredient source = Ingredient("소스", '~');
		Ingredient pickle = Ingredient("피클", '>');
		Ingredient onion = Ingredient("양파", '*');
		Ingredient cowPatty = Ingredient("소고기 패티", '#');
		Ingredient lettuce = Ingredient("양상추", '/');
		Ingredient tomato = Ingredient("토마토", '@');
		Ingredient hashbrown = Ingredient("해쉬브라운", '+');
		Ingredient bulgogiPatty = Ingredient("불고기 패티", '=');
		Ingredient chickenPatty = Ingredient("치킨 패티", '&');
		Ingredient shrimpPatty = Ingredient("새우 패티", '%');
		
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

		Burger doubleCheeseBurger = Burger("더블치즈버거", doubleCheeseBurgerRecipe);
		Burger shrimpBurger = Burger("새우버거", shrimpBurgerRecipe);
		Burger jinjeoChickenBurger = Burger("진저치킨버거", jinjeoChickenBurgerRecipe);
		Burger HashBrownCheeseBurger = Burger("더블치즈버거에 해쉬브라운", doubleCheeseBurgerRecipe);

		//Freshmans Initialize
		vector<Freshman> freshmans = {
			Freshman("민주", doubleCheeseBurger), Freshman("설희", shrimpBurger),
			Freshman("은서", jinjeoChickenBurger), Freshman("효창", HashBrownCheeseBurger)
		};

		//Senior Initialize
		Senior LimGeon = Senior();
public:
	void start() {
		/* Process */
		display.init();
		while (char key = _getch()) {
			switch (key) {
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
	}
};

int main(void) {
	MiniGame2 miniGame2 = MiniGame2();
	miniGame2.start();
	return 0;
}