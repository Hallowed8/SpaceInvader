#ifndef GAMEGUI_H
#define GAMEGUI_H


#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QBrush>
#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QRect>
#include <QSet>
#include <graphicobject.h>
#include <ship.h>
#include <myeventfilter.h>
#include "score.h"
#include "health.h"
#include "explosion.h"

class GameGui: public QGraphicsView{
    Q_OBJECT
public:
    GameGui(QWidget *parent = nullptr);
    QGraphicsScene* scene;
    QGraphicsView* view;
    QMediaPlayer* explosionSound;
    void startGameGui(QVector<Object *> &objects);
    void update(QVector<Object*>& objects);
    QVector<GraphicObject*> graphicObjects;
    Score * score;
private:
    QVector<Object*> objects;
    QMediaPlayer shotSound;
    void playShotSound();
    void gameOver();
    Object* player;
    MyEventFilter* keyFilter;
    Health* healthBar;
    Explosion* ex;
    bool playerDestroyed{false};
};
#endif // GAMEGUI_H
