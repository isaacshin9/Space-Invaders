#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QVector>
#include <QTimer>
#include "Player.h"
#include "Enemy.h"
#include "Score.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);

    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Score * score;
public slots:
    void moveAll();

private:
    QVector<QVector<Enemy *>> test;
    QVector<Enemy *> enemies;
    int direction;
    int dir = 0;
};

#endif // GAME_H
