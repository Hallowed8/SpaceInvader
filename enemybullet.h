#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "object.h"

class EnemyBullet : public Object
{
public:
    EnemyBullet(int hp, QPoint pos, QPoint size);
    void update() override;
};

#endif // ENEMYBULLET_H
