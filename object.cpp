#include "object.h"

Object::Object(int hp, QPoint pos, QPoint size)
{
    this->hp = hp;
    this->pos = pos;
    this->size = size;
}
int Object::getHp(){
    return this->hp;
}

void Object::changeHp(int hpChange)
{
    this->hp+=hpChange;
}
QPoint Object::getPos(){
    return this->pos;
}

QPoint Object::getSize()
{
    return this->size;
}
