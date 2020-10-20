#include "health.h"

Health::Health(int maxHp, QGraphicsItem *parent)
{
    this->health=maxHp;
    this->maxHealth=maxHp;
    setPixmap(QPixmap(":/graphic/SpaceInvader/red_rectangle.png").scaled(1024,10,
                      Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
void Health::changeValue(int currentValue)
{
    this->health=currentValue;
    int coef=1024/maxHealth;
    setPixmap(pixmap().scaled(coef*(this->health), pixmap().height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
