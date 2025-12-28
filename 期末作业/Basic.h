//Basic.h
#pragma once
#ifndef BASIC_H
#define BASIC_H
#include<ctime>

enum GameMode
{
	NoneGame,
	Mode_Level,
	Mode_Endless
};
const int ScreenX = 17;
const int ScreenY = 20;//屏幕大小
extern int BoatX, BoatY;//船坐标
extern char GameScreen[20][17];//游戏画面
extern bool EndlessGameRun;//无尽游戏运行状态
extern bool LevelGameRun;//关卡游戏运行状态
extern bool returnToMainMenu;
extern int life;
extern int Score;
extern int Level;
extern GameMode currentGameMode;
extern time_t gameTimeStart;//开始时间
extern int gameTimeMinute;//游戏分钟
extern int gameTimeSecond;//游戏秒
void RestartGame();
void cleanScreen();
extern int BulletFPS;//敌人移动帧数计时器
extern int EnemyFPS;//子弹移动帧数计时器
struct flyBoat {
	static const char Aboat = 'A';//船体
};
enum BulletType
{
	playerBullet,
	bossBullet
};
struct flyBullet
{
	BulletType type;
	int BulletX, BulletY;//子弹坐标（每一个子弹都不同）
	bool isActive = false;
	static const char Bullet = 'o';
};
static const int Max_Bullet = 20;//最大子弹数量
extern flyBullet Bulletpool[Max_Bullet];//把flybullet里所有的状态都放在bulletpool这个数组里，数组数量为maxbullet
#endif // BASIC_H
