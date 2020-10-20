#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsTextItem* parent=nullptr);
    void setScore(int score);
    int getScore();
private:
    int score;
};

#endif // SCORE_H
