#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QMediaPlayer>
#include <QPixmap>

#include "cruiser.h"
#include "fighter.h"
#include "bullet.h"
#include "enemy.h"
#include "enemybullet.h"

class GraphicObject: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GraphicObject(Object* obj, QGraphicsItem *parent = nullptr);
};

#endif // GRAPHICOBJECT_H
