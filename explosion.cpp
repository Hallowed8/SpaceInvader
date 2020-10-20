#include "explosion.h"


Explosion::Explosion(int height, int width, QGraphicsItem *parent):QObject (), QGraphicsPixmapItem (parent)
{
    this->timer  = new QTimer;
    this->i=1;
    this->height=height;
    this->width=width;
    connect(timer,SIGNAL(timeout()),this, SLOT(show()));
    timer->start(15);
}

void Explosion::show()
{
    QString PixmapDirectory;
        if(i<10){
            PixmapDirectory=
                    QString(":/graphic/explosion/SpaceInvader/explosion_1/image_part_00")+QString::number(i)+QString(".png");
        }
        else if(i>=10 && i<=48){
            PixmapDirectory=
                    QString(":/graphic/explosion/SpaceInvader/explosion_1/image_part_0")+QString::number(i)+QString(".png");
        }
        else {
            this->timer->stop();
            return;
        }
        setPixmap(QPixmap(PixmapDirectory).scaled(width,height));
        this->i++;
}
