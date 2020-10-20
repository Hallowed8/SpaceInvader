#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>

class Explosion: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Explosion(int height, int width, QGraphicsItem* parent = nullptr);
private slots:
    void show();
private:
    QTimer * timer;
    int i;
    int width;
    int height;
};

#endif // EXPLOSION_H
