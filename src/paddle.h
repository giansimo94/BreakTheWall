#ifndef PADDLE_H
#define PADDLE_H

#include <QPainter>
#include <QGraphicsItem>

/**
 * @brief
 * Classe utilizzata per la creazione del paddle
 */

class Paddle : public QGraphicsItem
{
public:
    Paddle();


private:
    QRectF rect;

    //Funzioni
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;




};

#endif // PADDLE_H
