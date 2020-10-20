#include "fighter.h"

Fighter::Fighter(int hp, QPoint pos, QPoint size, int speed):Ship(hp, pos, size, speed){}

void Fighter::attack(QPoint attackPos)
{
    QPoint bulletPos(attackPos);
    QPoint bulletSize(10,50);
    Object* bullet = new Bullet(20, bulletPos, bulletSize);
    this->newObjects.append(bullet);
}
void Fighter::update()
{
    updatePos();
    updateBullets();
}

void Fighter::updateBullets(){
    if(shotIterator == shotPeriod)
        shotIterator=0;
    if(keys.contains(Qt::Key_A) && shotIterator == 0){
        attack(QPoint(this->getPos().x()+this->getSize().x()/2-5,this->getPos().y()));
    }
    ++shotIterator;
    if(shotIterator ==0 && !keys.contains(Qt::Key_A)){
        shotIterator = 0;
    }
}
