#include "ship.h"

Ship::Ship(int hp, QPoint pos, QPoint size, int speed): Object(hp, pos, size)
{
    this->speed = speed;
}
QPoint Ship::getMoveStep()
{
    return this->moveStep;
}

void Ship::updatePos()
{
    setMoveStep();
    this->pos+=moveStep;
}

int Ship::moveByDiag()
{
    return speed/sqrt(2);
}

void Ship::keepInWindow()
{
    int marginX = this->size.x()/2;
    int marginY = this->size.y()/2;
    QPoint nextPos;
    nextPos = moveStep+pos;
    if(nextPos.x() <= 0-marginX)
        moveStep.setX(0);
    if(nextPos.y() <= 0-marginY)
        moveStep.setY(0);
    if(nextPos.x() >= 1024-marginX)
        moveStep.setX(0);
    if(nextPos.y() >= 768-marginY)
        moveStep.setY(0);
}

void Ship::setMoveStep() {
  if (this->keys.contains(Qt::Key_Right) && this->keys.contains(Qt::Key_Up)) {
      this->moveStep.setX(moveByDiag());
      this->moveStep.setY(-moveByDiag());
  } else if (this->keys.contains(Qt::Key_Right) && this->keys.contains(Qt::Key_Down)) {
      this->moveStep.setX(moveByDiag());
      this->moveStep.setY(moveByDiag());
  } else if (this->keys.contains(Qt::Key_Left) && this->keys.contains(Qt::Key_Down)) {
      this->moveStep.setX(-moveByDiag());
      this->moveStep.setY(moveByDiag());
  } else if (this->keys.contains(Qt::Key_Left) && this->keys.contains(Qt::Key_Up)) {
      this->moveStep.setX(-moveByDiag());
      this->moveStep.setY(-moveByDiag());
  } else if (this->keys.contains(Qt::Key_Up)) {
      this->moveStep.setX(0);
      this->moveStep.setY(-speed);
  } else if (this->keys.contains(Qt::Key_Right)) {
      this->moveStep.setX(speed);
      this->moveStep.setY(0);
  } else if (this->keys.contains(Qt::Key_Down)) {
      this->moveStep.setX(0);
      this->moveStep.setY(speed);
  } else if (this->keys.contains(Qt::Key_Left)) {
      this->moveStep.setX(-speed);
      this->moveStep.setY(0);
  }else{
      this->moveStep.setX(0);
      this->moveStep.setY(0);
  }
  keepInWindow();
}

