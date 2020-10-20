#include "enemybullet.h"


EnemyBullet::EnemyBullet(int hp, QPoint pos, QPoint size):Object(hp, pos, size){}

void EnemyBullet::update()
{
    QPoint moveStep(0,12);
    this->pos+=moveStep;
}
