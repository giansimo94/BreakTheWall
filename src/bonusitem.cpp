#include "bonusitem.h"


/**
 * Funzione che definisce alcune caratteristiche dell'oggetto Ball
 */

BonusItem::BonusItem()
{
    setcolor();
    visible = false;
    xpos = -50;
    ypos = -10;
    down = 1.3;
}

/**
 * Setta la posizione di un generico oggetto BonusItem
 * @param[in] x : ascissa
 * @param[in] y : ordinata
 */

void BonusItem::set_coord(qreal x, qreal y)
{
    setX(x);
    setY(y);
}

/**
 *  Funzione che muove il BonusItem verso il basso.
 */

void BonusItem::move_down()
{
    moveBy(0,down);

    if (y() >= 105)
        visible = false;

}

/**
 * This function, which is usually called by QGraphicsView, paints the contents of an item in local coordinates.
 */

void BonusItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QPen pen;

    switch (col_corrente)
    {
        case rosso:
                   {
                        pen.setColor(Qt::red);
                        brush.setColor(Qt::red);
                        break;
                   }
        case blu:
                   {
                        brush.setColor(Qt::blue);
                        pen.setColor(Qt::blue);
                        break;
                   }

        case giallo:
                   {

                        brush.setColor(Qt::yellow);
                        pen.setColor(Qt::yellow);
                        break;
                   }
        default:
                        break;
    }
    rect = boundingRect();
    // no need 2 paint
    if (visible){

        painter->setBrush(brush);
        painter->setPen(pen);
        painter->drawEllipse(rect);

    }
}


/**
 *
 * This pure virtual function defines the outer bounds of the item as a rectangle;
 * all painting must be restricted to inside an item's bounding rect.
 * QGraphicsView uses this to determine whether the item requires redrawing.
 *
 */

QRectF BonusItem::boundingRect() const
{
    return QRectF(xpos,ypos,10,10);
}

/**
 * Funzione che setta il colore scegliendolo casualmente.
 */

void BonusItem::setcolor()
{
    int num = qrand() % 3;
    col_corrente = static_cast<colore>(num);
}
