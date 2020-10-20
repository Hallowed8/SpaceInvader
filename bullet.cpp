#include "bullet.h"

Bullet::Bullet(int hp, QPoint pos, QPoint size):Object(hp, pos, size){}

void Bullet::update()
{
    QPoint moveStep(0,-15);
    this->pos+=moveStep;
}
