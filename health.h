#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Health :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Health(int maxHp, QGraphicsItem* parent=nullptr);
    void changeValue(int value);
private:
    int health;
    int maxHealth;
};

#endif // HEALTH_H
