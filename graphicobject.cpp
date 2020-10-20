#include "graphicobject.h"

GraphicObject::GraphicObject(Object* obj, QGraphicsItem *parent)
{
    if(Fighter* fig = dynamic_cast<Fighter*>(obj)){
        QPixmap pixmap = QPixmap(QString(":/graphic/fighter.png"));
        pixmap = pixmap.scaled(obj->getSize().x(),obj->getSize().y());
        setPixmap(pixmap);
    }
    else if (typeid(*obj)==typeid(Bullet)) {
        QPixmap pixmap = QPixmap(QString(":/graphic/SpaceInvader/blueAmmo.png"));
        pixmap = pixmap.scaled(obj->getSize().x(),obj->getSize().y());
        setPixmap(pixmap);
    }
    else if (typeid(*obj)==typeid(Enemy)) {
        QPixmap pixmap = QPixmap(QString(":/graphic/SpaceInvader/yellow_enemy_spaceship.png"));
        pixmap = pixmap.scaled(obj->getSize().x(),obj->getSize().y());
        setPixmap(pixmap);
    }
    else if (typeid(*obj)==typeid(EnemyBullet)) {
        QPixmap pixmap = QPixmap(QString(":/graphic/SpaceInvader/redAmmo.png"));
        pixmap = pixmap.scaled(obj->getSize().x(),obj->getSize().y());
        setPixmap(pixmap);
    }
    else if (typeid(*obj)==typeid(Cruiser)) {
        QPixmap pixmap = QPixmap(QString(":/graphic/SpaceInvader/cruiser.png"));
        pixmap = pixmap.scaled(obj->getSize().x(),obj->getSize().y());
        setPixmap(pixmap);
    }

}
