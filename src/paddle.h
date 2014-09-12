#ifndef PADDLE_H
#define PADDLE_H


#include <QtGui>
#include <QtCore>
#include <QGraphicsItem>

/**
 * Oggetto di tipo QGraphicsItem.
 */


class Paddle : public QGraphicsItem
{
public:
    Paddle();

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF rect;
    QRectF boundingRect() const;


};

#endif // PADDLE_H
