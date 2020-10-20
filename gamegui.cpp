#include "gamegui.h"

GameGui::GameGui(QWidget* parent)
{
    const int x_size=1024, y_size=768;
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,x_size,y_size);
    scene->setBackgroundBrush(QBrush(QImage(":/graphic/SpaceInvader/background.png").scaled(x_size,y_size)));

    // add a view to visualize the scene
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(x_size,y_size);
    view->show();
    shotSound.setMedia(QUrl("qrc:/sound/SpaceInvader/laser_sound.mp3"));
    //create an explosion sound
    explosionSound=new QMediaPlayer();
    explosionSound->setMedia(QUrl("qrc:/sound/SpaceInvader/explosion_very_small_pop.mp3"));
}

void GameGui::startGameGui(QVector<Object*>& objects)
{
    player = objects[0];

    GraphicObject* playerGraphic = new GraphicObject(player);
    graphicObjects.append(playerGraphic);
    playerGraphic->setPos(500,500);

    keyFilter = new MyEventFilter(&player->keys);
    scene->installEventFilter(keyFilter);
    healthBar = new Health(player->getHp());
    healthBar->setPos(0, scene->height()-healthBar->pixmap().height());
    scene->addItem(healthBar);

    //adding player's ship graphic
    if(!graphicObjects.isEmpty()){
        scene->addItem(graphicObjects[0]);
    }

    score = new Score();
    scene->addItem(score);

    view->show();
}

void GameGui::update(QVector<Object*>& objects)
{
    if(player->getHp()<=0 && !playerDestroyed){
        healthBar->hide();
        ex= new Explosion(140,140);
        ex->setPos(player->getPos());
        scene->addItem(ex);
        gameOver();
        playerDestroyed = true;
    }else{
        healthBar->changeValue(player->getHp());
    }
    if(graphicObjects.size() < objects.size()){
        int numberOfObjects = graphicObjects.size();
        for(int i=numberOfObjects; i<objects.size();++i){
            GraphicObject* graphicObj = new GraphicObject(objects[i]);
            scene->addItem(graphicObj);
            graphicObjects.append(graphicObj);
            if(typeid(*objects[i]) == typeid(Bullet)){
                if(shotSound.position()>100 && shotSound.state()==QMediaPlayer::PlayingState){
                    shotSound.setPosition(0);
                    shotSound.play();
                }
                else {
                    shotSound.play();
                }
            }
        }
    }
    for(int i = 0; i<graphicObjects.size(); i++){
        graphicObjects[i]->setPos(objects[i]->getPos());
    }
    view->show();
}

void GameGui::playShotSound()
{

}
void GameGui::gameOver()
{
    scene->removeEventFilter(keyFilter);
    QGraphicsSimpleTextItem* gameOver = new QGraphicsSimpleTextItem;
    gameOver->setText("Game Over");
    gameOver->setFont(QFont("times",46));
    gameOver->setPos(scene->width()/2-150,scene->height()/2-50);
    gameOver->setZValue(1);
    gameOver->setBrush(Qt::darkCyan);
    scene->addItem(gameOver);

}



