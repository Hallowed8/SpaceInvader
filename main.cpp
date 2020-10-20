#include <QApplication>

#include "game.h"
#include "gamegui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameGui* gameGui = new GameGui();
    Game* game = new  Game(gameGui, 1024, 768, 50);
    return a.exec();
}
