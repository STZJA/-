//Enemy.h
#ifndef ENEMY_H
#define ENEMY_H
enum EnemyType
{
	EasyEnemy=0,
	NormalEnemy,
	HardEnemy,
	DifficultEnemy,
	Wall1,Wall2,Wall3
};

struct BossEnemy {
	int x, y;           // Boss位置
	int health;         // boss当前血量
	int maxHealth;      // boss最大血量
	int state;          // Boss状态：0=下降中，1=左右移动，2=攻击状态
	int moveDirection;  // 移动方向：1=向右，-1=向左
	int moveTimer;      // boss移动计时器
	bool isAlive;       // 是否存活
};

extern BossEnemy boss;
struct flyEnemy {
	//通用属性
	int EnemyX, EnemyY;//敌人坐标
	bool isActive = false;//敌人是否活跃

	//不同属性
	EnemyType type;
	int health;
	int speed;
	char EnemyDisplay;
};
static const int Max_Enemy = 80;//一次最多80个敌人
extern flyEnemy Enemypool[Max_Enemy];//把敌人都放在enemypool这个数组里
//设计一个敌人对象池存放敌人

void SetupEnemyType(flyEnemy* enemy, EnemyType type);
void createEnemy();
void moveEnemy();
#endif//敌人类型