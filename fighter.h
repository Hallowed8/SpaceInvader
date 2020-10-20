#ifndef FIGHTER_H
#define FIGHTER_H

#include "ship.h"
#include "bullet.h"
#include "QVector"

class Fighter: public Ship
{
public:
    Fighter(int hp, QPoint pos, QPoint size, int speed);
    Fighter();
    void update() override;
    void attack(QPoint attackPos) override;
private:
    void updateBullets();
    int shotPeriod{6};
    int shotIterator{0};
};
#endif // FIGHTER_H
