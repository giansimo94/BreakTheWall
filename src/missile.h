#ifndef MISSILE_H
#define MISSILE_H

#include <QPainter>
#include <QGraphicsItem>

/**
 * @brief
 * Classe utilizzata per la creazione dei missili
 */

class Missile : public QGraphicsItem
{
public:
    Missile();
    bool visible;
    void move();


private:
    QRectF rect;
    qreal xpos;
    qreal ypos;
    qreal speed;

    //Funzioni
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);


};

#endif // MISSILE_H
