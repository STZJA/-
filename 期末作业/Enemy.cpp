//Enemy.cpp
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<Windows.h>
#include"Enemy.h"
#include"Basic.h"
#include"Difficulty.h"
#include"Menu.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"
using namespace std;

void SetupEnemyType(flyEnemy* enemy,EnemyType type) {//enemy作为指向flyenmey的指针使用
	enemy->isActive = true;//把对象设置成活跃

	//不同类型选择
	switch (type) {
	case EasyEnemy:
		enemy->health = 1;
		enemy->speed = 10;
		enemy->EnemyDisplay = 'X';
		break;
	case NormalEnemy:
		enemy->health = 2;
		enemy->speed = 20;
		enemy->EnemyDisplay = 'X';
		break;
	case HardEnemy:
		enemy->health = 3;
		enemy->speed = 30;
		enemy->EnemyDisplay = 'X';
		break;
	case DifficultEnemy:
		enemy->health = 5;
		enemy->speed = 30;
		enemy->EnemyDisplay = 'X';
		break;
	}
}
void createEnemy() {
	EnemyType SelectType;
	if (currentGameMode==Mode_Endless)
	{
		int getScore = Score;
		EnemyWeights weights = GetWeightsByScore(getScore);
		SelectType = SelectTypeByWeights(weights);
	}
	else if (currentGameMode==Mode_Level&&Level<=4)
	{
		int getLevel = Level;
		EnemyWeights weights = GetWeightsByLevel(getLevel);
		SelectType = SelectTypeByWeights(weights);
	}
	else if (currentGameMode == Mode_Level && Level ==5)
	{
		int getLevel = Level;
		EnemyWeights weights = GetWeightsByLevel(getLevel);
		SelectType = SelectTypeByWeights(weights);
	}
	else
	{
		SelectType = EasyEnemy;
	}

	for (int i = 0; i < Max_Enemy; i++)
	{
		if (Enemypool[i].isActive == false) {
			Enemypool[i].type = SelectType;
			Enemypool[i].EnemyX = rand() % (ScreenX - 2) + 1;
			Enemypool[i].EnemyY = 0;
			Enemypool[i].isActive = true;
			SetupEnemyType(&Enemypool[i], SelectType);
			break;
		}
	}
}

void moveEnemy() {
	EnemyFPS++;
	for (int i = 0; i < Max_Enemy; i++)
	{
		if (Enemypool[i].isActive==true)
		{
			if (EnemyFPS % Enemypool[i].speed == 0&&Enemypool[i].speed>0)
			{
				Enemypool[i].EnemyY++;
				if (Enemypool[i].EnemyY > ScreenY)
				{
					Enemypool[i].isActive = false;
					life--;
				}
			}
		}
	}//怪物移动时间
	static int EnemySpawn = 0;
	EnemySpawn++;
	if (EnemySpawn%10==0)
	{
		createEnemy();
		EnemySpawn = 0;
	}//怪物生成时间
}