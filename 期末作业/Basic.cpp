//Basic.cpp
//该文件用来存放基础游戏元素并定义（除了游戏画面大小固定外）
#include"Basic.h"
#include<Windows.h>
int BoatX = (ScreenX - 1) / 2, BoatY = ScreenY - 1;//船坐标
char GameScreen[ScreenY][ScreenX];//游戏画面
int life = 5;
int Score = 0;
int Level = 1;
GameMode currentGameMode = NoneGame;
flyBullet Bulletpool[Max_Bullet];//在这里定义Bulletpool数组
int BulletFPS = 0;//设置一个帧计时器（计算哪一帧发射子弹）
int gameTimeMinute = 0;
int gameTimeSecond = 0;
time_t gameTimeStart = time(nullptr);
bool returnToMainMenu = false;

#include"Enemy.h"
flyEnemy Enemypool[Max_Enemy];//在这里定义Enemypool数组
int EnemyFPS = 0;


void RestartGame() {
	life = 5;
	Score = 0;
	for (int i = 0; i < Max_Enemy; i++)
	{
		Enemypool[i].isActive = false;
	}
	for (int i = 0; i < Max_Bullet; i++)
	{
		Bulletpool[i].isActive = false;
	}
	BoatX = (ScreenX - 1) / 2, BoatY = ScreenY - 1;//重置船坐标
	BulletFPS = 0;
	EnemyFPS = 0;
	gameTimeStart = time(nullptr);
	gameTimeMinute = 0;
	gameTimeSecond = 0;
	returnToMainMenu = false;
}

void cleanScreen() {
	system("cls");
}//清理屏幕上内容

