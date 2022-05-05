#include <QApplication>
#include <QGraphicsScene>
#include "Game.h"
#include <QGraphicsView>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game -> show();

    return a.exec();
}
