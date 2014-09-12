#include "paddle.h"

/**
 * Funzione che definisce alcune caratteristiche dell'oggetto Paddle.
 */
Paddle::Paddle()
{
    setFlag(ItemIsFocusable);

}

/**
 *
 * This pure virtual function defines the outer bounds of the item as a rectangle;
 * all painting must be restricted to inside an item's bounding rect.
 * QGraphicsView uses this to determine whether the item requires redrawing.
 *
 */

QRectF Paddle::boundingRect() const
{
    return   QRectF(0,50,45,10);
}


/**
 * This function, which is usually called by QGraphicsView, paints the contents of an item in local coordinates.
 */

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QRectF rect = boundingRect();

    QBrush brush(Qt::blue);
    QPen pen(Qt::blue);

    QLinearGradient grad(0,50,45,10);
    grad.setColorAt(0.0,Qt::green);
    grad.setColorAt(0.5,Qt::black);

    painter->setBrush(grad);
    painter->drawRect(rect);
}
