#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/Images/Bullet.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer -> start(50);
}

void Bullet::move(){
    // move up
    setPos(x(), y()-10);
    if(pos().y() + pixmap().height() < 0){
       scene() -> removeItem(this);
       delete this;
    }
}
