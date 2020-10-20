#include "menu.h"

Menu::Menu(QWidget *parent)
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

    //create an item to put into the scene
    ship = new Fighter();
    player = new ShipGui(ship,":/graphic/fighter.png");

    //add item to the scene
    scene->addItem(player);
    player->setPos(view->width()/2, view->height() - 250);

    //add buttons for starting the game, etc
    startButton = new QPushButton("&Start Game", view);
    startButton->setGeometry(QRect(QPoint(50, 50), QSize(150, 50)));
    connect(startButton,SIGNAL(released()), this, SLOT(handleStart()));

    quitButton = new QPushButton("&Quit game", view);
    quitButton->setGeometry(QRect(QPoint(50, 150), QSize(150, 50)));
    connect(quitButton, SIGNAL(released()), this, SLOT(handleQuit()));


    chgShipButton = new QPushButton("&Change ship", view);
    chgShipButton->setGeometry(QRect(QPoint(320, 690), QSize(150, 50)));
    connect(chgShipButton, SIGNAL(released()), this, SLOT(handleShipChg()));
    view->show();
    quitButton->show();
    startButton->show();
    chgShipButton->show();
}
void Menu::handleStart()
{
    quitButton->hide();
    startButton->hide();
    chgShipButton->hide();
    scene->installEventFilter(ship);
    game = new GameGui(this->scene, this->view, this->player);
}

void Menu::handleQuit()
{
    QCoreApplication::quit();
}

void Menu::handleShipChg()
{
    if (default_ship){
        //create an item to put into the scene
        scene->removeItem(player);
        delete player;
        delete ship;
        ship= new Fighter();
        player = new ShipGui(ship,":/graphic/fighter.png");
        scene->addItem(player);
        player->setPos(view->width()/2, view->height() - 250);
        view->show();
        default_ship=false;
    }
//    else{
//        scene->removeItem(player);
//        delete player;
//        delete ship;
//        ship = new Cruiser();
//        player = new ShipGui(ship);
//        scene->addItem(player);
//        player->setPos(view->width()/2, view->height() - 250);
//        view->show();
//        default_ship=true;
//    }
}

