#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int enemyType, QGraphicsItem * parent=0);
    void moveRight(int enemy);
    void moveLeft(int enemy);
    void moveDown();
    bool wasHit();
    int typeEnemy;
private:
    int count;
};
#endif // ENEMY_H
