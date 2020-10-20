#ifndef OBJECT_H
#define OBJECT_H

#include <QPoint>
#include <QObject>
#include <QSet>
#include <QVector>

class Object
{
public:
    Object(int hp, QPoint pos, QPoint size);
    virtual ~Object(){}

    int getHp();
    void changeHp(int hpChange);
    QPoint getPos();
    QPoint getSize();
    virtual void update() = 0;
    QSet<Qt::Key> keys;
    QVector<Object*> newObjects;

protected:
    int hp;
    QPoint pos;
    QPoint size;
};

#endif // OBJECT_H
