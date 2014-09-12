#include "src/brick.h"

/**
 * Funzione che definisce alcune caratteristiche dell'oggetto Brick.
 */

Brick::Brick()
{
   // Setto la variabile destroyed di ogni brick a false
   destroyed = false;
}

/**
 * This function, which is usually called by QGraphicsView, paints the contents of an item in local coordinates.
 */

void Brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    rect = boundingRect();

    // no need 2 paint
    if (!destroyed){
        QBrush brush(Qt::blue);
        painter->setBrush(brush);
        painter->drawRect(rect);
    }
}


/**
 *
 * This pure virtual function defines the outer bounds of the item as a rectangle;
 * all painting must be restricted to inside an item's bounding rect.
 * QGraphicsView uses this to determine whether the item requires redrawing.
 *
 */

QRectF Brick::boundingRect() const
{
    return QRectF(xpos,ypos,30,10);
}
