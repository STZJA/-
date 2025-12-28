//difficulty.cpp
#include<iostream>
#include<cstdlib>
#include"Difficulty.h"
#include"Enemy.h"
using namespace std;

EnemyWeights GetWeightsByScore(int score) {
	EnemyWeights result;
	if (score<300)
	{
		result.EasyE = 1.0;
		result.NormalE = 0.0;
		result.HardE = 0.0;
		result.DifficultE = 0.0;
	}
	else if (score >= 300 && score < 600) {
		result.EasyE = 0.7;
		result.NormalE = 0.3;
		result.HardE = 0.0;
		result.DifficultE = 0.0;
	}
	else if (score >= 600 && score < 1000) {
		result.EasyE = 0.5;
		result.NormalE = 0.3;
		result.HardE = 0.2;
		result.DifficultE = 0.0;
	}
	else if (score >= 1000&&score<2000) {
		result.EasyE = 0.4;
		result.NormalE = 0.3;
		result.HardE = 0.2;
		result.DifficultE = 0.1;
	}
	else if (score>=2000&&score<3000)
	{
		result.EasyE = 0.2;
		result.NormalE = 0.4;
		result.HardE = 0.3;
		result.DifficultE = 0.1;
	}
	else if (score>=3000&&score<3500)
	{
		result.EasyE = 0.2;
		result.NormalE = 0.3;
		result.HardE = 0.3;
		result.DifficultE = 0.2;
	}
	else if (score>=3500&&score<4000)
	{
		result.EasyE = 0.1;
		result.NormalE = 0.3;
		result.HardE = 0.3;
		result.DifficultE = 0.3;
	}
	return result;
}//定义在不同分数的时候每种敌人刷新概率

EnemyType SelectTypeByWeights(EnemyWeights weights) {
	float totalWeights = weights.EasyE + weights.NormalE + weights.HardE + weights.DifficultE;
	float randomWeights = rand()/(float)RAND_MAX*totalWeights;
	if (randomWeights<=weights.EasyE)
	{
		return EasyEnemy;
	}
	else if (randomWeights>weights.EasyE&&randomWeights<=(weights.EasyE+weights.NormalE))
	{
		return NormalEnemy;
	}
	else if (randomWeights > (weights.EasyE + weights.NormalE) && randomWeights <= (totalWeights - weights.DifficultE)) 
	{
		return HardEnemy;
	}
	else if (randomWeights>(totalWeights - weights.DifficultE)&&randomWeights<totalWeights)
	{
		return DifficultEnemy;
	}
}//根据敌人概率选择敌人（用随机数的方法）

EnemyWeights GetWeightsByLevel(int level) {
	EnemyWeights result;
	if (level==1)
	{
		result.EasyE = 1.0;
		result.NormalE = 0.0;
		result.HardE = 0.0;
		result.DifficultE = 0.0;
	}
	else if (level==2) {
		result.EasyE = 0.6;
		result.NormalE = 0.4;
		result.HardE = 0.0;
		result.DifficultE = 0.0;
	}
	else if (level==3) {
		result.EasyE = 0.5;
		result.NormalE = 0.3;
		result.HardE = 0.2;
		result.DifficultE = 0.0;
	}
	else if (level==4) {
		result.EasyE = 0.3;
		result.NormalE = 0.4;
		result.HardE = 0.3;
		result.DifficultE = 0.0;
	}
	else if (level == 5) {
		result.EasyE = 0.35;
		result.NormalE = 0.45;
		result.HardE = 0.15;
		result.DifficultE = 0.05;
	}
	return result;
}//定义不同关卡的时候刷敌人的概率