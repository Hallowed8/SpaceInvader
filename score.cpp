#include "score.h"

Score::Score(QGraphicsTextItem* parent): QGraphicsTextItem (parent){
    // initialize the score to zero
    this->score=0;

    // draw the text
    setPlainText("Score: "+ QString::number(score));
    setDefaultTextColor(Qt::darkCyan);
    setFont(QFont("times",16));
}

void Score::setScore(int score){
    this->score  = score;
    setPlainText("Score: "+ QString::number(score));
}

int Score::getScore(){
    return score;
}
