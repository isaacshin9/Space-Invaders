#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>

Game::Game(QWidget *parent):  QGraphicsView( parent ){
    //create scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,800);
    scene->setBackgroundBrush(Qt::black);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);

    //create player
    Player * player = new Player();
    player -> setPos(scene -> width()/2, scene -> height() - player->pixmap().height());

    //make focused
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();
    scene -> addItem(player);

    //spawn enemies
    int x = 0;
    int y = 40;
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 12; i++){
            if(j > 0){
                Enemy * enemy = new Enemy(j);
                enemy -> setPos(x + 35, y);
                scene -> addItem(enemy);
                x += 70;
                enemies.push_back(enemy);
            }else{
                Enemy * enemy = new Enemy(j);
                enemy -> setPos(x + 35, y);
                scene -> addItem(enemy);
                x += 70;
                enemies.push_back(enemy);
            }
        }
        test.push_back(enemies);
        x = 0;
        y += 50;
    }

    QTimer *pSpaceshipTimer = new QTimer();
    connect(pSpaceshipTimer, SIGNAL(timeout()), this, SLOT(moveAll()));

    pSpaceshipTimer->start( 500 );
//    moveAll();

    // create score
    score = new Score();
    scene -> addItem(score);

    show();
}

void Game::moveAll(){
    if(dir == 0){
        if(test[2].back()->x() + test[2].back()->pixmap().width() * 2 < 1200){
            for(int j = 0; j < test[2].size(); j++){
                if(test[2][j]->typeEnemy == 0){
                    test[2][j] -> moveRight(0);
                }else if(test[2][j]->typeEnemy == 1){
                    test[2][j] -> moveRight(1);
                }else if(test[2][j]->typeEnemy == 2){
                    test[2][j] -> moveRight(2);
                }
            }
        }
        else{
            dir = 1;
            for(int j = 0; j < test[2].size(); j++){
                test[2][j] -> moveDown();
            }
        }
    }else if(dir == 1){
        if(test[2].front()->x() - test[2].front()->pixmap().width() > 0){
            for(int j = 0; j < test[2].size(); j++){
                if(test[2][j]->typeEnemy == 0){
                    test[2][j] -> moveLeft(0);
                }else if(test[2][j]->typeEnemy == 1){
                    test[2][j] -> moveLeft(1);
                }else if(test[2][j]->typeEnemy == 2){
                    test[2][j] -> moveLeft(2);
                }
            }
        }
        else{
            dir = 0;
            for(int j = 0; j < test[2].size(); j++){
                test[2][j] -> moveDown();
            }
        }
    }
}


