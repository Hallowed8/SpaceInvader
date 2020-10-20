#ifndef GAME_H
#define GAME_H

#include <QVector>
#include <QTimer>
#include <QObject>
#include <windows.h>
#include <QTimer>
#include <stdlib.h>

#include "object.h"
#include "cruiser.h"
#include "fighter.h"
#include "gamegui.h"
#include "enemy.h"
#include "bullet.h"
#include "enemybullet.h"

class Game: public QObject
{
    Q_OBJECT
public:
    Game(GameGui* gameGui,int width, int height, int updateFrequency);
    int getWidth(){ return width; }
    int getHeight(){ return height; }
    int setExplosion(QPoint pos, QPoint size);
private:
    GameGui* gameGui;
    QVector<Object*> objects;
    int width;
    int height;
    int updateFrequency;
    int score{0};
    bool isRunning;
    QTimer* gameLoopTimer;
    void collisionHandler();
    void objectCollision();
    void updatePos();
    void updateGraphic();
    void spawnEnemy();
    void updateObjects();
    Explosion* ex;
    int spawnIterator{0};
    int spawnPeriod{60};
private slots:
    void updateState();
};

#endif // GAME_H
