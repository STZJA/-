#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>
#include"Basic.h"
#include"Enemy.h"
#include"Boss.h"
#include"Difficulty.h"
#include"Endless_mode.h"
#include"Level_mode.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"

using namespace std;
bool LevelGameRun = true;

void Level1() {
	const int Level1_Time = 20;//第一关20s
	//设置游戏关卡
	currentGameMode = Mode_Level;
	Level = 1;

	gameTimeStart = time(nullptr);//初始时间
	LevelGameRun = true;

	while (LevelGameRun) {
		bool ContiuneToNextLevel=false;
		RestartGame();
		LevelGameRun = true;
		while (life > 0 && LevelGameRun)
		{	
			double nowTime = difftime(time(nullptr), gameTimeStart);
			int remainingTime = Level1_Time - (int)nowTime;

			cleanScreen();
			keyboardMove();
			drawNewScreen();
			cout << "-------LEVEL 1-------" << endl;
			cout << "Time: " << remainingTime << endl;
			Sleep(50);
			updateGame();


			if (remainingTime <= 0) {
				cleanScreen();
				Level++;
				cout << "恭喜通过第1关！" << endl;
				cout << "按E键进入下一关" << endl;
				cout << "按Q键退出游戏" << endl;
				char levelKey = _getch();
				if (levelKey == 'e' || levelKey == 'E')
				{
					cleanScreen();
					ContiuneToNextLevel = true;
				}
				if (levelKey == 'q' || levelKey == 'Q')
				{
					ContiuneToNextLevel = false;
					returnToMainMenu = true;
					return;
				}
			}
			if (ContiuneToNextLevel)
			{
				Level2();
				break;
			}
			// 如果生命值为0，游戏结束
			if (life <= 0) {
				cleanScreen();
				cout << "第1关失败！" << endl;
				cout << "按R重新开始，按Q退出" << endl;
				bool wait = true;
				while (wait) {
					if (_kbhit()) {
						char key = _getch();
						if (key == 'r' || key == 'R') {
							LevelGameRun = true;
							wait = false;
						}
						else if (key == 'q' || key == 'Q') {
							LevelGameRun = false;
							wait = false;
						}
					}
				}
				break;
			}
		}
	}
	currentGameMode = NoneGame;
}

void Level2(){
	const int Level2_Time = 40;//第二关40s
	//设置游戏关卡
	currentGameMode = Mode_Level;
	Level = 2;

	gameTimeStart = time(nullptr);//初始时间
	LevelGameRun = true;

	while (LevelGameRun) {
		bool ContiuneToNextLevel = false;
		RestartGame();
		LevelGameRun = true;
		while (life > 0 && LevelGameRun)
		{
			double nowTime = difftime(time(nullptr), gameTimeStart);
			int remainingTime = Level2_Time - (int)nowTime;

			cleanScreen();
			keyboardMove();
			drawNewScreen();
			cout << "-------LEVEL 2-------" << endl;
			cout << "Time: " << remainingTime << endl;
			Sleep(50);
			updateGame();

			if (remainingTime <= 0) {
				cleanScreen();
				Level++;
				cout << "恭喜通过第2关！" << endl;
				cout << "按E键进入下一关" << endl;
				cout << "按Q键退出游戏" << endl;
				char levelKey = _getch();
				if (levelKey == 'e' || levelKey == 'E')
				{
					cleanScreen();
					ContiuneToNextLevel = true;
				}
				if (levelKey == 'q' || levelKey == 'Q')
				{
					ContiuneToNextLevel = false;
					returnToMainMenu = true;
					return;
				}
			}
			if (ContiuneToNextLevel)
			{
				Level3();
				break;
			}
			// 如果生命值为0，游戏结束
			if (life <= 0) {
				cleanScreen();
				cout << "第2关失败！" << endl;
				cout << "按R重新开始，按Q退出" << endl;
				bool wait = true;
				while (wait) {
					if (_kbhit()) {
						char key = _getch();
						if (key == 'r' || key == 'R') {
							LevelGameRun = true;
							wait = false;
						}
						else if (key == 'q' || key == 'Q') {
							LevelGameRun = false;
							returnToMainMenu = true;
							wait = false;
						}
					}
				}
				break;
			}
		}
	}
	currentGameMode = NoneGame;
}

void Level3(){
	const int Level3_Time = 60;//第三关60s
	//设置游戏关卡
	currentGameMode = Mode_Level;
	Level = 3;

	gameTimeStart = time(nullptr);//初始时间
	LevelGameRun = true;

	while (LevelGameRun) {
		bool ContiuneToNextLevel = false;
		RestartGame();
		LevelGameRun = true;
		while (life > 0 && LevelGameRun)
		{
			double nowTime = difftime(time(nullptr), gameTimeStart);
			int remainingTime = Level3_Time - (int)nowTime;

			cleanScreen();
			keyboardMove();
			drawNewScreen();
			cout << "-------LEVEL 3-------" << endl;
			cout << "Time: " << remainingTime << endl;
			Sleep(50);
			updateGame();
			if (remainingTime <= 0) {
				cleanScreen();
				Level++;
				cout << "恭喜通过第3关！" << endl;
				cout << "按E键进入下一关" << endl;
				cout << "按Q键退出游戏" << endl;
				char levelKey = _getch();
				if (levelKey == 'e' || levelKey == 'E')
				{
					cleanScreen();
					ContiuneToNextLevel = true;
				}
				if (levelKey == 'q' || levelKey == 'Q')
				{
					ContiuneToNextLevel = false;
					returnToMainMenu = true;
					return;
				}
			}
			if (ContiuneToNextLevel)
			{
				Level4();
				break;
			}
			// 如果生命值为0，游戏结束
			if (life <= 0) {
				cleanScreen();
				cout << "第3关失败！" << endl;
				cout << "按R重新开始，按Q退出" << endl;
				bool wait = true;
				while (wait) {
					if (_kbhit()) {
						char key = _getch();
						if (key == 'r' || key == 'R') {
							LevelGameRun = true;
							wait = false;
						}
						else if (key == 'q' || key == 'Q') {
							LevelGameRun = false;
							returnToMainMenu = true;
							wait = false;
						}
					}
				}
				break;
			}
		}
	}
	currentGameMode = NoneGame;
}

void Level4(){
	const int Level4_Time = 90;//第四关90s
	//设置游戏关卡
	currentGameMode = Mode_Level;
	Level = 4;

	gameTimeStart = time(nullptr);//初始时间
	LevelGameRun = true;

	while (LevelGameRun) {
		bool ContiuneToNextLevel = false;
		RestartGame();
		LevelGameRun = true;
		while (life > 0 && LevelGameRun)
		{
			double nowTime = difftime(time(nullptr), gameTimeStart);
			int remainingTime = Level4_Time - (int)nowTime;

			cleanScreen();
			keyboardMove();
			drawNewScreen();
			cout << "-------LEVEL 4-------" << endl;
			cout << "Time: " << remainingTime << endl;
			Sleep(50);
			updateGame();

			if (remainingTime <= 0) {
				cleanScreen();
				Level++;
				cout << "恭喜通过第4关！" << endl;
				cout << "按E键进入下一关" << endl;
				cout << "按Q键退出游戏" << endl;
				char levelKey = _getch();
				if (levelKey == 'e' || levelKey == 'E')
				{
					cleanScreen();
					ContiuneToNextLevel = true;
				}
				if (levelKey == 'q' || levelKey == 'Q')
				{
					ContiuneToNextLevel = false;
					returnToMainMenu = true;
					return;
				}
			}
			if (ContiuneToNextLevel)
			{
				Level5();
				break;
			}
			// 如果生命值为0，游戏结束
			if (life <= 0) {
				cleanScreen();
				cout << "第4关失败！" << endl;
				cout << "按R重新开始，按Q退出" << endl;
				bool wait = true;
				while (wait) {
					if (_kbhit()) {
						char key = _getch();
						if (key == 'r' || key == 'R') {
							LevelGameRun = true;
							wait = false;
						}
						else if (key == 'q' || key == 'Q') {
							LevelGameRun = false;
							returnToMainMenu = true;
							wait = false;
						}
					}
				}
				break;
			}
		}
	}
	currentGameMode = NoneGame;
}

void Level5(){
	currentGameMode = Mode_Level;
	Level = 5;
	gameTimeStart = time(nullptr);
	LevelGameRun = true;

	life = 5;  // Boss 关给满生命值
	Score = 0;  // Boss 关单独计分

	for (int i = 0; i < Max_Bullet; i++) {
		Bulletpool[i].isActive = false;
	}

	//初始化 Boss
	boss.x = (ScreenX - 1) / 2; 
	boss.y = 1; 
	boss.health = 50;
	boss.maxHealth = 50;
	boss.state = 0;  // 下降状态
	boss.moveDirection = 1; //初始向右移动
	boss.moveTimer = 0;
	boss.isAlive = true;
	createBossWalls();
	showBossEntrance();

	while (LevelGameRun) {
		bool ContinueToEnd = false;
		RestartGameForBoss(); 

		while (life > 0 && boss.isAlive && LevelGameRun) {
			double nowTime = difftime(time(nullptr), gameTimeStart);
			int elapsedTime = (int)nowTime;

			cleanScreen();
			keyboardMove();
			updateBossLevel();
			drawBossScreen();
			cout << "用时: " << elapsedTime << " 秒" << endl;
			Sleep(50); 

			if (!boss.isAlive) {
				cleanScreen();
				cout << "恭喜击败 Boss！" << endl;
				cout << "最终得分: " << Score << endl;
				cout << "用时: " << elapsedTime << " 秒" << endl;
				cout << "按 Q 键返回主菜单" << endl;
				bool wait = true;
				while (wait) {
					if (_kbhit()) {
						char key = _getch();
						if (key == 'q' || key == 'Q') {
							LevelGameRun = false;
							returnToMainMenu = true;
							wait = false;
						}
					}
				}
				break;
			}
		}

		if (life <= 0 && boss.isAlive) {
			cleanScreen();
			cout << "Boss 击败了你！" << endl;
			cout << "你的得分: " << Score << endl;
			cout << "按 R 重新挑战，按 Q 返回主菜单" << endl;

			bool wait = true;
			while (wait) {
				if (_kbhit()) {
					char key = _getch();
					if (key == 'r' || key == 'R') {
						LevelGameRun = true;
						wait = false;
						// 重新初始化 Boss
						boss.isAlive = true;
						boss.health = 50;
						boss.x = (ScreenX - 1) / 2;
						boss.y = 7;  // 跳过入场动画
						createBossWalls();
					}
					else if (key == 'q' || key == 'Q') {
						LevelGameRun = false;
						returnToMainMenu = true;
						wait = false;
					}
				}
			}
		}
	}

	currentGameMode = NoneGame;
}
