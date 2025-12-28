// Boss.cpp
#include "Enemy.h"
#include "Basic.h"
#include "Boss.h"
#include<iostream>
#include<Windows.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"
using namespace std;
BossEnemy boss;//定义在enemy.h中
static bool allWallsDestroyed = false;

void createBossWalls() {
    // 创建三行墙，每行15个墙块
    int wallIndex = 1;

    // 第一行墙（最上面的墙）
    for (int x = 1; x <= ScreenX - 2; x++) {
        if (wallIndex < Max_Enemy) {
            Enemypool[wallIndex].type = Wall3;
            Enemypool[wallIndex].EnemyX = x;
            Enemypool[wallIndex].EnemyY = 9;  // 第9行
            Enemypool[wallIndex].health = 3;
            Enemypool[wallIndex].speed = 0;   // 墙不移动
            Enemypool[wallIndex].EnemyDisplay = 'X';
            Enemypool[wallIndex].isActive = true;
            wallIndex++;
        }
    }

    // 第二行墙
    for (int x = 1; x <= ScreenX - 2; x++) {
        if (wallIndex < Max_Enemy) {
            Enemypool[wallIndex].type = Wall2;
            Enemypool[wallIndex].EnemyX = x;
            Enemypool[wallIndex].EnemyY = 10;  // 第10行
            Enemypool[wallIndex].health = 2;
            Enemypool[wallIndex].speed = 0;
            Enemypool[wallIndex].EnemyDisplay = 'X';
            Enemypool[wallIndex].isActive = true;
            wallIndex++;
        }
    }

    // 第三行墙（最下面的墙）
    for (int x = 1; x <= ScreenX - 2; x++) {
        if (wallIndex < Max_Enemy) {
            Enemypool[wallIndex].type = Wall1;
            Enemypool[wallIndex].EnemyX = x;
            Enemypool[wallIndex].EnemyY = 11;  // 第11行
            Enemypool[wallIndex].health = 1;
            Enemypool[wallIndex].speed = 0;
            Enemypool[wallIndex].EnemyDisplay = 'X';
            Enemypool[wallIndex].isActive = true;
            wallIndex++;
        }
    }
}//批量创建墙，然后设定墙的属性

void showBossEntrance() {
    cleanScreen();
    cout << "-------BOSS 来袭！---------" << endl;
    Sleep(1000);
    cout << "提示：把墙全部打破会有惊喜噢" << endl;
    Sleep(3000);

    for (int y = 1; y <= 7; y++) {  //从顶上到第7行
        cleanScreen();
        boss.y = y;

        for (int screenY = 0; screenY < ScreenY; screenY++) {
            for (int screenX = 0; screenX < ScreenX; screenX++) {
                if (screenY == boss.y && screenX == boss.x) {
                    cout << RED << 'X' << RESET; 
                }
                else if (screenX == 0 || screenX == ScreenX - 1 || screenY == 0) {
                    cout << '#';
                }
                else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        Sleep(500);  // 每下降一格暂停0.5秒
    }
    Sleep(1000);
}//boss出场动画

void updateBossLevel() {
    BulletFPS++;
    if (BulletFPS % 3 == 0) {
        for (int i = 0; i < Max_Bullet / 2; i++) { 
            if (Bulletpool[i].isActive == false) {
                Bulletpool[i].isActive = true;
                Bulletpool[i].BulletX = BoatX;
                Bulletpool[i].BulletY = BoatY - 1; 
                break;
            }
        }
        BulletFPS = 0;
    }//玩家子弹逻辑
    updateBossMovement();
    updateBullets();
    bossAttack();
    checkBossCollisions();
    checkWalls();
    if (allWallsDestroyed)//如果没墙了就开始刷新敌人
    {
        moveEnemy();
        checkEnemy();
        enemyLogic();
    }
    if (boss.health <= 0) {
        boss.isAlive = false;
    }
}

void updateBossMovement() {
    static int moveCounter = 0;
    moveCounter++;

    if (boss.state == 0) {
        boss.state = 1;
    }

    if (boss.state == 1 && moveCounter % 10 == 0) {
        boss.x += boss.moveDirection;

        if (boss.x <= 1) {
            boss.x = 1;
            boss.moveDirection = 1;  // 向右
        }
        else if (boss.x >= ScreenX - 2) {
            boss.x = ScreenX - 2;
            boss.moveDirection = -1; // 向左
        }//检查有没有碰墙
    }
}//boss左右移动

void checkBossCollisions() {//墙的计分逻辑
    for (int i = 0; i < Max_Bullet; i++) {
        if (Bulletpool[i].isActive) {
            for (int j = 1; j < Max_Enemy; j++) {  // 从1开始，0留给Boss
                if (Enemypool[j].isActive &&
                    Enemypool[j].EnemyX == Bulletpool[i].BulletX &&
                    Enemypool[j].EnemyY == Bulletpool[i].BulletY) {

                    // 击中墙
                    Enemypool[j].health--;
                    if (Enemypool[j].health <= 0) {
                        Enemypool[j].isActive = false;
                        Score += 5; 
                    }
                    Bulletpool[i].isActive = false;
                    break;
                }
            }

            if (Bulletpool[i].isActive &&
                Bulletpool[i].BulletX == boss.x &&
                Bulletpool[i].BulletY == boss.y) {

                // 检查Boss前面是否有墙
                bool wallInFront = false;
                for (int j = 1; j < Max_Enemy; j++) {
                    if (Enemypool[j].isActive &&
                        Enemypool[j].EnemyX == boss.x &&Enemypool[j].EnemyY < boss.y) {
                        wallInFront = true;
                        break;
                    }
                }

                if (!wallInFront) {
                    boss.health--;
                    Bulletpool[i].isActive = false;
                    Score += 10;  
                }
            }
        }
    }
}

void drawBossScreen() {
    system("cls");
    for (int y = 0; y < ScreenY; y++) {
        for (int x = 0; x < ScreenX; x++) {
            if (y == 0) {
                cout << '#'; 
            }
            else if (x == 0 || x == ScreenX - 1) {
                cout << '#'; 
            }
            else if (y == boss.y && x == boss.x) {
                cout << RED << 'X' << RESET; 
            }
            else if (y == BoatY && x == BoatX) {
                cout << 'A';
            }
            else {
                bool hasWall = false;
                for (int i = 1; i < Max_Enemy; i++) {
                    if (Enemypool[i].isActive &&Enemypool[i].EnemyX == x && Enemypool[i].EnemyY == y) {
                        hasWall = true;
                        switch (Enemypool[i].type) {
                        case EasyEnemy:
                        case Wall1: cout << WHITE << 'X' << RESET; break;
                        case NormalEnemy:
                        case Wall2: cout << GREEN << 'X' << RESET; break;
                        case HardEnemy:
                        case Wall3: cout << YELLOW << 'X' << RESET; break;
                        case DifficultEnemy:cout << RED << 'V' << RESET; break;
                        default: cout << '#'; break;
                        }
                        break;
                    }
                }

                // 检查是否有子弹
                if (!hasWall) {
                    bool hasBullet = false;
                    for (int i = 0; i < Max_Bullet; i++) {
                        if (Bulletpool[i].isActive &&Bulletpool[i].BulletX == x &&Bulletpool[i].BulletY == y) {
                            if (Bulletpool[i].type==playerBullet)
                            {
                                cout <<WHITE<< 'o'<<RESET;
                            }
                            else if (Bulletpool[i].type == bossBullet)
                            {
                                cout << RED << 'o' << RESET;
                            }
                            hasBullet = true;
                            break;
                        }
                    }

                    if (!hasBullet && !hasWall) {
                        cout << ' ';
                    }
                }
            }
        }
        cout << endl;
    }

    // 显示游戏信息
    cout << "\n====== BOSS 关 ======" << endl;
    cout << "生命: " << life << endl;
    cout << "得分: " << Score << endl;
    cout << "Boss血量: ";
    int healthBars = boss.health / 5;  // 每5点血量一个方块
    for (int i = 0; i < 10; i++) {
        if (i < healthBars) {
            cout << RED << "■" << RESET;
        }
        else {
            cout << "□";
        }
    }
    cout << " (" << boss.health << "/" << boss.maxHealth << ")" << endl;

    // 显示墙的状态
    int wallsLeft = 0;//剩余墙的数量
    for (int i = 1; i < Max_Enemy; i++) {

        if (Enemypool[i].isActive) {
            wallsLeft++;
        }
    }
    cout << "剩余墙块: " << wallsLeft << endl;
}

void updateBullets() {
    for (int i = 0; i < Max_Bullet / 2; i++) {
        if (Bulletpool[i].isActive) {
            Bulletpool[i].type = playerBullet;
            Bulletpool[i].BulletY--;
            if (Bulletpool[i].BulletY < 1) { 
                Bulletpool[i].isActive = false;
            }
        }
    }
    for (int i = Max_Bullet / 2; i < Max_Bullet; i++) {
        if (Bulletpool[i].isActive) {
            Bulletpool[i].type = bossBullet;
            Bulletpool[i].BulletY++;
            if (Bulletpool[i].BulletX == BoatX &&Bulletpool[i].BulletY == BoatY) {
                life--; 
                Bulletpool[i].isActive = false;
            }
            if (Bulletpool[i].BulletY >= ScreenY - 1) {
                Bulletpool[i].isActive = false;
            }
        }
    }
}//子弹逻辑

void checkWalls() {
    int wall1Count = 0, wall2Count = 0, wall3Count = 0;

    for (int i = 1; i < Max_Enemy; i++) { 
        if (Enemypool[i].isActive) {

            switch (Enemypool[i].type) {
            case Wall1:
                wall1Count++;
                break;
            case Wall2:
                wall2Count++;
                if (Enemypool[i].health == 1) {
                    Enemypool[i].type = Wall1;
                    Enemypool[i].EnemyDisplay = 'X';
                }
                break;
            case Wall3:
                wall3Count++;
                if (Enemypool[i].health == 2) {
                    Enemypool[i].type = Wall2;
                    Enemypool[i].EnemyDisplay = 'X';
                }
                else if (Enemypool[i].health == 1) {
                    Enemypool[i].type = Wall1;
                    Enemypool[i].EnemyDisplay = 'X';
                }
                break;
            }
            if (Enemypool[i].health <= 0) {
                Enemypool[i].isActive = false;
                switch (Enemypool[i].type) {
                case Wall1: Score += 5; break;
                case Wall2: Score += 10; break;
                case Wall3: Score += 15; break;
                }
            }
        }
    }
    static bool alreadyTriggered = false;
    int totalWalls = wall1Count + wall2Count + wall3Count;
    if (totalWalls == 0&&!alreadyTriggered) {
        allWallsDestroyed = true;
        alreadyTriggered = true;
        cout << RED << "警告：Boss失去保护！普通敌人开始进攻！" << RESET << endl;
    }
}//检查墙的数量+定义墙的状态

void bossAttack() {
    static int bossAttackTimer = 0;
    bossAttackTimer++;

    if (boss.health <= 30 && boss.health > 0) {
        // 血量越低，攻击频率越高（每 20-30 帧攻击一次）
        int attackFrequency = 30 - ((30 - boss.health) / 2);
        attackFrequency = max(20, attackFrequency);  // 最低 20 帧

        if (bossAttackTimer % attackFrequency == 0) {
            int bulletsToFire = 1;
            if (boss.health <= 15) bulletsToFire = 2;  // 血量更低时发射更多子弹
            for (int b = 0; b < bulletsToFire; b++) {

                for (int i = Max_Bullet / 2; i < Max_Bullet; i++) { // 使用后一半子弹槽作为 Boss 子弹
                    if (!Bulletpool[i].isActive) {
                        Bulletpool[i].isActive = true;
                        if (bulletsToFire == 1) {
                            Bulletpool[i].BulletX = boss.x;
                        }
                        else {
                            // 双发：从 Boss 两侧发射
                            Bulletpool[i].BulletX = boss.x + (b == 0 ? -1 : 1);
                        }
                        Bulletpool[i].BulletY = boss.y + 1; // 从 Boss 下方发射
                        break;
                    }
                }
            }
        }
    }
}

void RestartGameForBoss() {
    for (int i = 0; i < Max_Bullet; i++) {
        Bulletpool[i].isActive = false;
    }
    BoatX = (ScreenX - 1) / 2;
    BoatY = ScreenY - 1;
    BulletFPS = 0;
    life = 5;
    Score = 0;
    allWallsDestroyed = false;
}//重置boss关

void checkEnemy() {
    for (int i = 0; i < Max_Bullet / 2; i++) {  // 只检查玩家子弹
        if (Bulletpool[i].isActive && Bulletpool[i].type == playerBullet) {
            for (int j = 1; j < Max_Enemy; j++) {
                // 只检查普通敌人
                if (Enemypool[j].isActive &&
                    (Enemypool[j].type == EasyEnemy ||
                        Enemypool[j].type == NormalEnemy ||
                        Enemypool[j].type == HardEnemy ||
                        Enemypool[j].type == DifficultEnemy) &&
                    Enemypool[j].EnemyX == Bulletpool[i].BulletX &&
                    Enemypool[j].EnemyY == Bulletpool[i].BulletY) 
                {
                    Enemypool[j].health--;
                    if (Enemypool[j].health <= 0) {
                        Enemypool[j].isActive = false;
                        switch (Enemypool[j].type) {
                        case EasyEnemy:
                            Score += 10;
                            break;
                        case NormalEnemy:
                            Score += 20;
                            break;
                        case HardEnemy:
                            Score += 30;
                            break;
                        case DifficultEnemy:
                            Score += 40;
                            break;
                        }
                    }
                    Bulletpool[i].isActive = false;
                    break;
                }
            }
        }
    }
}

void enemyLogic() {
    for (int i = 1; i < Max_Enemy; i++) {
        if (Enemypool[i].isActive &&
            (Enemypool[i].type == EasyEnemy ||
                Enemypool[i].type == NormalEnemy ||
                Enemypool[i].type == HardEnemy ||
                Enemypool[i].type == DifficultEnemy))
        {
            if (Enemypool[i].EnemyY >= ScreenY - 1 ||
                (Enemypool[i].EnemyX == BoatX && Enemypool[i].EnemyY == BoatY)) {
                life--;
                Enemypool[i].isActive = false;
            }
        }
    }
}