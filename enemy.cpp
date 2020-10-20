#include "enemy.h"

Enemy::Enemy(int hp, QPoint pos, QPoint size, int speed, int attackPeriod):Object (hp, pos, size)
{
    this->speed = speed;
    this->attackPeriod = rand()%(attackPeriod+25)+15;
}

void Enemy::update()
{
    pos.setY(pos.y()+speed);
    randomizedAttack();
}
void Enemy::attack()
{
    QPoint bulletPos(this->getPos().x()+this->getSize().x()/2-5,this->getPos().y()+this->getSize().y());
    QPoint bulletSize(10,50);
    Object* bullet = new EnemyBullet(20, bulletPos, bulletSize);
    this->newObjects.append(bullet);
}

void Enemy::randomizedAttack(){
    if(attackIterator > attackPeriod){
        attack();
        attackIterator = 0;
    }
    ++attackIterator;
}
