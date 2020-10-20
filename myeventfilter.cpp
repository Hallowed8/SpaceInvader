#include "myeventfilter.h"

MyEventFilter::MyEventFilter(QSet<Qt::Key>* keys)
{
    this->keys = keys;
}
void MyEventFilter::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat()){
        switch ( event->key() )
        {
        case Qt::Key_Left:
            keys->insert(Qt::Key_Left);
            break;
        case Qt::Key_Right:
            keys->insert(Qt::Key_Right);
            break;
        case Qt::Key_Up:
            keys->insert(Qt::Key_Up);
            break;
        case Qt::Key_Down:
            keys->insert(Qt::Key_Down);
            break;
        case Qt::Key_A:
            keys->insert(Qt::Key_A);
            break;
        }
    }
}
void MyEventFilter::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat()){
        switch ( event->key() )
        {
        case Qt::Key_Left:
            keys->remove(Qt::Key_Left);
            break;
        case Qt::Key_Right:
            keys->remove(Qt::Key_Right);
            break;
        case Qt::Key_Up:
            keys->remove(Qt::Key_Up);
            break;
        case Qt::Key_Down:
            keys->remove(Qt::Key_Down);
            break;
        case Qt::Key_A:
            keys->remove(Qt::Key_A);
            break;
        }
    }
}



bool MyEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        keyPressEvent(key);
    }
    else if(event->type()==QEvent::KeyRelease){
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        keyReleaseEvent(key);
    }
    else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
