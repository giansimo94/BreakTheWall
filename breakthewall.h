#ifndef BREAKTHEWALL_H
#define BREAKTHEWALL_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QtCore>
#include <QGraphicsScene>
#include <QMessageBox>
#include <paddle.h>
#include <ball.h>
#include <brick.h>


namespace Ui {
class BreakTheWall;
}

/**
 * @brief
 * Classe principale utilizzata per la gestione del gioco.
 */

class BreakTheWall : public QDialog
{
    Q_OBJECT

public:
    explicit BreakTheWall(QWidget *parent = 0);
    ~BreakTheWall();
    void collision();
    void createWall();

private:
    Ui::BreakTheWall *ui;
    QGraphicsScene *scene;
    Ball *ball;
    Paddle *paddle;
    Brick *brick[50];
    qreal xBrick;
    qreal yBrick;
    int timeId;
    int Brickcount;
    bool running;

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);
};

#endif // BREAKTHEWALL_H
