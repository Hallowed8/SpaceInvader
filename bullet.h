#ifndef BULLET_H
#define BULLET_H

#include "object.h"

class Bullet : public Object
{
public:
    Bullet(int hp, QPoint pos, QPoint size);
    void update() override;
};

#endif // BULLET_H
