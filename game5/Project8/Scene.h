#pragma once

//colors
enum {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

class Scene {


public: 
	void ScreenClear();
	void ScreenFlipping();
	void ScreenInit();
	void ScreenRelease();
	void Console();
	void GotoXY(int x, int y);
	void setColor(int forground, int background);
};
