#ifndef BREAKTHEWALL_H
#define BREAKTHEWALL_H

#include <QDialog>
#include <QInputDialog>
#include <QtGui>
#include <QLabel>
#include <QtCore>
#include <QGraphicsScene>
#include <QMessageBox>
#include <src/paddle.h>
#include <src/ball.h>
#include <src/brick.h>
#include <src/missile.h>
#include <src/bonusitem.h>
#include <src/topscores.h>
#include <src/save_load.h>


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

public slots:
    void endBonusTime();

private:
    Ui::BreakTheWall *ui;
    QTimer timer;
    QGraphicsScene *scene;
    Ball *ball;
    Paddle *paddle;
    Missile *missile[100];
    Brick *brick[50];
    BonusItem *bonus[50];
    Score TopScores[10];
    int timeId;
    bool running;
    qreal xBrick;
    qreal yBrick;
    int Brickcount;
    int Bonuscount;
    int Missilecount;
    int Points;
    int extraPoints;    /**< Variabile che conta il numero di brick distrutti consecutivamente senza la ricollisione con il paddle */
    bool super_ball;    /**< Se settata a true la pallina non modifica la sua direzione nel caso essa collida con un brick */
    bool move_wall;     /**< Se settata a true il muro inizia a spostarsi */
    bool fire_mode;     /**< Se settata a true l'utente ha la possibilità di sparare dei missili */
    Save_Load save_load;
    char* name;

    // Funzioni
    void check_update_TopScore(Score TopScores[],int points,int nEle, char* name);
    void check_collision();
    void createWall();
    void check_colore(BonusItem *BItem);
    void inizializza(Score TopScores[]);
    void muovi_muro(Brick *wall[]);
    bool check_wall_collision();
    char* get_name();

protected:
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);
};

#endif // BREAKTHEWALL_H
