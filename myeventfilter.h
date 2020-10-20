#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QObject>
#include <QKeyEvent>
#include <QSet>
#include <QPoint>
class MyEventFilter: public QObject
{
    Q_OBJECT
public:
    MyEventFilter(QSet<Qt::Key>* keys);
protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
private:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    QSet<Qt::Key>* keys;
};

#endif // MYEVENTFILTER_H
