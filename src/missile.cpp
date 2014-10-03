#include "missile.h"

/**
 * Funzione che definisce alcune caratteristiche dell'oggetto Ball
 */

Missile::Missile()
{
    setFlag(ItemIsFocusable);
    visible = true;
    xpos = 5;
    ypos = 40;
    speed = 2;
}

/** 
 * @brief
 * Muove il missile
 *
 * Se questo raggiunge il lato superiore del rettangolo di gioco,
 * lo rende invisibile
 *
 */

void Missile::move()
{
    moveBy(0,-speed);

    if (y() <= -500)
        visible = false;
}

/**
 *
 * This pure virtual function defines the outer bounds of the item as a rectangle;
 * all painting must be restricted to inside an item's bounding rect.
 * QGraphicsView uses this to determine whether the item requires redrawing.
 *
 */


QRectF Missile::boundingRect() const
{
    return  QRectF(xpos,ypos,5,10);
}


/**
 * This function, which is usually called by QGraphicsView, paints the contents of an item in local coordinates.
 */

void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    rect = boundingRect();

    if (visible)
    {
       QLinearGradient grad(0,50,45,10);
       grad.setColorAt(0.0,Qt::green);
       grad.setColorAt(0.5,Qt::black);

       painter->setBrush(grad);
       painter->drawRect(rect);
    }

}
