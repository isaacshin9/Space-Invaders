#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game;

Enemy::Enemy(int enemyType, QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    count = 1;
    if(enemyType == 0){
        setPixmap(QPixmap(":/Images/enemy1stage1.png"));
        typeEnemy = enemyType;
    }else if(enemyType == 1){
        setPixmap(QPixmap(":/Images/enemy2stage1.png"));
        typeEnemy = enemyType;
    }else if(enemyType == 2){
        setPixmap(QPixmap(":/Images/enemy3stage1.png"));
        typeEnemy = enemyType;
    }
}

void Enemy::moveRight(int enemy){
    count++;
    setPos(x() + 50, y());

    if(count % 2 == 0 && enemy == 0){
        setPixmap(QPixmap(":/Images/enemy1stage2.png"));
    }else if(enemy == 0 && count % 2 != 0){
        setPixmap(QPixmap(":/Images/enemy1stage1.png"));
    }
    if(count % 2 == 0 && enemy == 1){
        setPixmap(QPixmap(":/Images/enemy2stage2.png"));
    }else if(enemy == 1 && count % 2 != 0){
        setPixmap(QPixmap(":/Images/enemy2stage1.png"));
    }
    if(count % 2 == 0 && enemy == 2){
        setPixmap(QPixmap(":/Images/enemy3stage2.png"));
    }else if(enemy == 2 && count % 2 != 0){
        setPixmap(QPixmap(":/Images/enemy3stage1.png"));
    }
}

void Enemy::moveLeft(int enemy){
    count++;
    setPos(x() - 50, y());

    if(count % 2 == 0 && enemy == 0){
        setPixmap(QPixmap(":/Images/enemy1stage2.png"));
    }else if(enemy == 0 && count % 2 != 0){
        setPixmap(QPixmap(":/Images/enemy1stage1.png"));
    }
    if(count % 2 == 0 && enemy == 1){
        setPixmap(QPixmap(":/Images/enemy2stage2.png"));
    }else if(enemy == 1 && count % 2 != 0){
        setPixmap(QPixmap(":/Images/enemy2stage1.png"));
    }
    if(count % 2 == 0 && enemy == 2){
        setPixmap(QPixmap(":/Images/enemy3stage2.png"));
    }else if(enemy == 2 && count % 2 != 0){
        setPixmap(QPixmap(":/Images/enemy3stage1.png"));
    }
}

void Enemy::moveDown(){
    setPos(x(), y() + pixmap().height());
}

bool Enemy::wasHit(){
    QList<QGraphicsItem *>  colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(* (colliding_items[i])) == typeid(Bullet)){
            // increase score
            game -> score -> increase();

            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);

            delete colliding_items[i];
            delete this;
            return true;
        }
    }
    return false;
}

