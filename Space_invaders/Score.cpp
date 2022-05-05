#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initial score
    score = 0;

    // show score
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Score::increase(){
    score += 10;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
