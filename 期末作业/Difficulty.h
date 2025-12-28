//difficulty.h
#pragma once
#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include "Enemy.h"

struct EnemyWeights
{
	float EasyE;
	float NormalE;
	float HardE;
	float DifficultE;
	EnemyWeights(float e = 0, float n = 0, float h = 0, float d = 0) :
		EasyE(e), NormalE(n), HardE(h), DifficultE(d){ }//¹¹Ôìº¯Êý
};
EnemyWeights GetWeightsByScore(int score);
EnemyType SelectTypeByWeights(EnemyWeights weights);
EnemyWeights GetWeightsByLevel(int level);

#endif // DIFFICULTY.H

