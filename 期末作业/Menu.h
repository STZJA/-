//Menu.h
#ifndef MENU_H 
#define MENU_H

enum GameChoice
	{
		Nothing,
		Levelmode,
		Endlessmode,
		Quit
	};
void mainDesktop();
void keyboardChoice();
GameChoice showMenu();
void RestartMenu();

#endif // !MENU_H;
