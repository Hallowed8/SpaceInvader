#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"
#include "bullet.h"
#include "enemybullet.h"
#include <stdlib.h>
class Enemy: public Object
{
public:
    Enemy(int hp, QPoint pos, QPoint size, int speed, int attackPeriod);
    void update() override;
private:
    int speed;
    void attack();
    void randomizedAttack();
    int attackPeriod;
    int attackIterator{0};
};

#endif // ENEMY_H
