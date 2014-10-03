#ifndef BALL_H
#define BALL_H

#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>

/**
 * @brief
 * Classe utilizzata per la creazione dell'oggetto ball
 */

class Ball : public QGraphicsItem
{
public:
    Ball();
    qreal getXdir();
    qreal getYdir();
    void setXDir(qreal x);
    void setYDir(qreal y);
    void move();

private:

    QRectF rect;
    qreal xmove ;/**< coordinata di movimento della pallina rispetto all'ascissa */
    qreal ymove ; /**< coordinata di movimento della pallina rispetto all'ordinata */

    //Funzioni
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;

};

#endif // BALL_H
