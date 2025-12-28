#include"Menu.h"
#include <iostream>
#include<string>
#include<conio.h>
#include<Windows.h>


using namespace std;
static const int ScreenX = 20, ScreenY = 20;
string static style[ScreenY][ScreenX];
string static title[] = { "太","空","射","击","游","戏" };
int titleStart = 7;
int arrowStart = 8;
int keyboard;
string static gamechoice1[] = { "1",".","闯","关","模","式"," " };
string static gamechoice2[] = { "2",".","无","尽","模","式"," " };
string static gameStop[] = { "3",".","退","出","游","戏"," " };
void mainDesktop() {
    for (int y = 0; y < ScreenY; y++)
    {
        if (y == 0 || y == ScreenY - 1) {
            for (int x = 0; x < ScreenX; x++)
            {
                style[y][x] = "——";
            }
        }
        else
        {
            for (int x = 0; x < ScreenX; x++)
            {
                if (x == 0 || x == ScreenX - 1) {
                    style[y][x] = "｜";
                }
                else
                {
                    style[y][x] = "　";
                }
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        style[7][titleStart + i] = title[i];
    }
    for (int i = 0; i < 6; i++) {
        style[8][titleStart + i] = gamechoice1[i];
    }
    for (int i = 0; i < 6; i++) {
        style[9][titleStart + i] = gamechoice2[i];
    }
    for (int i = 0; i < 6; i++) {
        style[10][titleStart + i] = gameStop[i];
    }
    for (int i = 8; i <= 10; i++) {
        style[i][titleStart - 1] = " ";
    }
    style[arrowStart][titleStart - 1] = "→";
    for (int i = 0; i < ScreenY; i++)
    {
        for (int j = 0; j < ScreenX; j++) {
            cout << style[i][j];
        }
        cout << endl;
    }
    cout << "\nW/S控制上下移动，Enter确认" << endl;
}
void keyboardChoice() {
    if (_kbhit()) {
        keyboard = _getch();
        switch (keyboard)
        {
        case 's':
            arrowStart++;
            style[arrowStart][titleStart - 1] = "→";
            style[arrowStart - 1][titleStart - 1] = " ";
            break;
        case 'S':
            arrowStart++;
            style[arrowStart][titleStart - 1] = "→";
            style[arrowStart - 1][titleStart - 1] = " ";
            break;
        case 'w':
            arrowStart--;
            style[arrowStart][titleStart - 1] = "→";
            style[arrowStart + 1][titleStart - 1] = " ";
            break;
        case 'W':
            arrowStart--;
            style[arrowStart][titleStart - 1] = "→";
            style[arrowStart + 1][titleStart - 1] = " ";
            break;
            }
        }
    if (arrowStart > 10)
    {
        arrowStart = 10;
    }
    else if (arrowStart < 8)
    {
        arrowStart = 8;
    }
}
GameChoice showMenu() {
    while (true)
    {
        system("cls");
        mainDesktop();
        keyboardChoice();
        if (keyboard == 13)
        {
            switch (arrowStart)
            {
            case 8:
                return Levelmode;
                break;
            case 9:
                return Endlessmode;
                break;
            case 10:
                return Quit;
                break;
            }
        }
        return Nothing;
    }
}

void RestartMenu() {
    keyboard = 0;
}