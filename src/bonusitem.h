#ifndef BONUSITEM_H
#define BONUSITEM_H

#include <QPainter>
#include <QGraphicsItem>


/**
 * @brief
 * Classe utilizzata per la creazione dei Bonus
 */

class BonusItem : public QGraphicsItem
{
public:
    BonusItem();
    bool visible;
    void set_coord(qreal x, qreal y);
    void move_down();
    enum colore { giallo,blu,rosso };
    colore col_corrente;

private:
    QRectF rect;
    qreal xpos;
    qreal ypos;
    qreal down;

    //Funzioni
    void setcolor();
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *);
    QRectF boundingRect() const;
};

#endif // BONUSITEM_H
