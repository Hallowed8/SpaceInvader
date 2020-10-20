#include "cruiser.h"

Cruiser::Cruiser(int hp, QPoint pos, QPoint size, int speed):Ship(hp, pos, size, speed){}

void Cruiser::attack(QPoint attackPos)
{
    QPoint bulletPos(attackPos);
    QPoint bulletSize(10,50);
    Object* bullet = new Bullet(40, bulletPos, bulletSize);
    this->newObjects.append(bullet);
}
void Cruiser::update()
{
    updatePos();
    updateBullets();
}

void Cruiser::updateBullets(){
    if(shotIterator == shotPeriod)
        shotIterator=0;
    if(keys.contains(Qt::Key_A) && shotIterator == 0){
        attack(QPoint(this->getPos().x()+this->getSize().x()/2-5,this->getPos().y()));
    }else if (keys.contains(Qt::Key_A) && shotIterator == shotPeriod/3) {
        attack(QPoint(this->getPos().x()+this->getSize().x()-5,this->getPos().y()));
    }else if (keys.contains(Qt::Key_A) && shotIterator == shotPeriod*2/3) {
        attack(QPoint(this->getPos().x()-5,this->getPos().y()));
    }
    ++shotIterator;
    if(shotIterator ==0 && !keys.contains(Qt::Key_A)){
        shotIterator = 0;
    }
}
