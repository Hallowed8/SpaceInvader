#ifndef SHIP_H
#define SHIP_H
#include <QSet>
#include <QEvent>
#include <QTimer>
#include <QKeyEvent>
#include <QObject>
#include <QString>
#include <cmath>
#include "object.h"

class Ship: public Object
{
public:
    Ship(int hp, QPoint pos, QPoint size, int speed);
    QPoint getMoveStep();
protected:
    virtual void attack(QPoint pos) = 0;
    void updatePos();
private:
    QPoint moveStep;
    void setMoveStep();
    int speed;
    int moveByDiag();
    void keepInWindow();
};

#endif // SHIP_H
