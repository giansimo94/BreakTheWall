#ifndef BRICK_H
#define BRICK_H

#include <QPainter>
#include <QGraphicsItem>

/**
 * @brief
 * Classe utilizzata per la creazione dei Bricks che costituiscono il muro
 */

class Brick :  public QGraphicsItem
{
public:
    Brick();
    qreal xpos; /**< Ascissa dello spigolo superiore sinistro di un generico mattone*/
    qreal ypos; /**< Ordinata dello spigolo superiore sinistro di un generico mattone */
    bool destroyed;  /**< Se settata a true, il brick non viene ridisegnato */

private:
    QRectF rect;

    //Funzioni
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;

};

#endif // BRICK_H
