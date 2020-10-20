#ifndef CRUISER_H
#define CRUISER_H

#include "ship.h"
#include "bullet.h"
#include "QVector"


class Cruiser: public Ship
{
public:
    Cruiser(int hp, QPoint pos, QPoint size, int speed);
    Cruiser();
    void update() override;
    void attack(QPoint pos) override;
private:
    void updateBullets();
    int shotPeriod{18};
    int shotIterator{0};
};
#endif // CRUISER_H
