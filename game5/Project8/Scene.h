#pragma once

//colors
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15

class Scene {

private:
	//static int g_nScreenIndex;
	//static HANDLE g_hScreen[2];

public: 
	void ScreenClear();
	void ScreenFlipping();
	void ScreenInit();
	void ScreenRelease();
	void Console();
	void GotoXY(int x, int y);
	void setColor(int forground, int background);
};
