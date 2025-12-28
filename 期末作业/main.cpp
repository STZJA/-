//qimo.cpp
#include<Windows.h>
#include<ctime>
#include"Basic.h"
#include"Menu.h"
#include"Endless_mode.h"
#include"Level_mode.h"
extern bool isGameRun;
int main() {
	srand(time(0));
	system("title Ì«¿ÕÉä»÷ÓÎÏ·");
	bool mainGameRun = true;
	while (mainGameRun)
	{

		RestartMenu();
		GameChoice choice = showMenu();
		switch (choice) {
		case Levelmode:
			Level1();
			if (returnToMainMenu)
			{
				returnToMainMenu = false;
			}
			break;
		case Endlessmode:
			EndlessMode();
			break;
		case Quit:
			mainGameRun = false;
			break;
		case Nothing:
			break;
		}
	}
	return 0;
}