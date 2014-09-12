#ifndef BRICK_H
#define BRICK_H

#include <QtGui>
#include <QtCore>
#include <QGraphicsItem>

/**
 * Oggetto di tipo QGraphicsItem.
 */


class Brick :  public QGraphicsItem
{
public:
    Brick();
    qreal xpos; /**< Ascissa dello spigolo superiore sinistro di un generico mattone*/
    qreal ypos; /**< Ordinata dello spigolo superiore sinistro di un generico mattone */
    bool destroyed;  /**< Se settata a true, il brick non viene ridisegnato */

private:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;
    QRectF rect;

};

#endif // BRICK_H
