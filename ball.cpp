#include "ball.h"
#include <QMessageBox>

/**
 * Funzione che definisce alcune caratteristiche dell'oggetto Ball
 */
Ball::Ball()
{
        setFlag(ItemIsFocusable);

        /*
         * Inzializza le coordinate di movimento.
         * L'angolazione iniziale è casuale.
         */

        setYDir(3);
        if (qrand() % 2)
            setXDir(qrand() % 6);
        else
            setXDir(-(qrand() % 6));
}

/**
 *
 * This pure virtual function defines the outer bounds of the item as a rectangle;
 * all painting must be restricted to inside an item's bounding rect.
 * QGraphicsView uses this to determine whether the item requires redrawing.
 *
 */
QRectF Ball::boundingRect() const
{
    return QRectF (18,40,10,10) ;
}

/**
 * This function, which is usually called by QGraphicsView, paints the contents of an item in local coordinates.
 */

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    rect = boundingRect();
    QLinearGradient grad(15,15,10,10);
    grad.setColorAt(0.0,Qt::black);
    grad.setColorAt(1.0,Qt::gray);
    painter->setBrush(grad);
    painter->drawEllipse(rect);
}
/**
 *   Funzione che muove la pallina mantenendola
 *   all'interno del rettangolo del gioco
 */

void Ball::move()
{
    moveBy(getXdir(), -getYdir());

    // Controlla collisione con lato sinistro del rettangolo
    if (x() <= -170)

        setXDir(-getXdir());

    // Controlla collisione con lato destro del rettangolo
    if (x() >= 170)

        setXDir(-getXdir());

    // Controlla collisione con il bordo superiore del rettangolo
    if (y() <= -535)

        setYDir(-getYdir());
}

/**
 * Funzione di scrittura.
 *
 * Setta la variabile xmove al valore della variabile in ingresso
 *
 * @param[in] x coordinata di movimento della pallina
 *              rispetto all'ascissa.
 */
void Ball::setXDir(qreal x)
{
    xmove = x;
}

/**
 * Funzione di scrittura.
 *
 * Setta la variabile ymove al valore della variabile in ingresso
 *
 * @param[in] y coordinata di movimento della pallina
 *              rispetto all'ordinata.
 */

void Ball::setYDir(qreal y)
{
    ymove = y;
}

/**
 * Funzione di lettura.
 *
 * @return Il valore della variabile xmove
 */

qreal Ball::getXdir()
{
    return xmove;  //coordinata di movimento rispetto all'ascissa
}

/**
 * Funzione di lettura.
 *
 * @return Il valore della variabile ymove
 */

qreal Ball::getYdir()
{
    return ymove;  //coordinata di movimento rispetto all'ordinata
}
