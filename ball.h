#ifndef BALL_H
#define BALL_H

#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>

/**
 * Oggetto di tipo QGraphicsItem.
 */

class Ball : public QGraphicsItem
{
public:
    Ball();
    void setXDir(qreal x);
    void setYDir(qreal y);
    qreal getXdir();
    qreal getYdir();
    void move();

private:

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;
    QRectF rect;
    qreal xmove;
    qreal ymove;

};

#endif // BALL_H
