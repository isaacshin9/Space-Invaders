#include "Player.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/Images/ship.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_A){
        if(pos().x() > 0){
            setPos(x()-10,y());
        }
    }else if(event->key() == Qt::Key_D){
        if(pos().x() + pixmap().width() < scene()->width()){
            setPos(x()+10,y());
        }
    }else if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10,y());
        }
    }else if(event->key() == Qt::Key_Right){
        if(pos().x() + pixmap().width() < scene()->width()){
            setPos(x()+10,y());
        }
    }else if(event->key() == Qt::Key_Space){
        //make bullet
        Bullet * bullet = new Bullet();
        bullet -> setPos(x() + (pixmap().width() / 2.1),y() - pixmap().height() + 20);
        scene() -> addItem(bullet);
    }
}
