/**
 * @mainpage
 * Libreria grafica utilizzata : QT.\n
 *
 * La struttura del codice si basa sui tre oggetti principali del gioco, implementati nelle rispettive classi:
 *
 *
 * Ball\n
 * Paddle\n
 * Brick
 *
 * La Gestione del gioco avviene all'interno di BreakTheWall
 *
 * @author Gianpaolo Simone
 */

#include "breakthewall.h"
#include "ui_breakthewall.h"
#include <QDebug>

/**
 * Funzione che inizializza le variabili
 * e crea la scena aggiungendo tutte le componenti/oggetti.
 *
 */
BreakTheWall::BreakTheWall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BreakTheWall)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Inizializza le variabili
    running = false;
    Brickcount=0;

    // Crea e setta la scena
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //Crea il muro ::createWall
    createWall();

    //Crea ed aggiunge alla scena un oggetto Ball
    ball = new Ball;
    scene->addItem(ball);

    /*
     * Crea ed aggiunge alla scena un oggetto Paddle,
     * attivandone il suo Flag 'focus'
     */

    paddle = new Paddle;
    scene->addItem(paddle);
    setFocus();

    // Definisce una penna e disegna il rettangolo del gioco
    QPen pen(Qt::black);
    pen.setWidth(4);

    QLine up(-155,-500,200,-500);
    QLine left(-155,100,-155,-500);
    QLine right(200,-500,200,100);
    QLine down(-155,100,200,100);

    scene->addLine(up,pen);
    scene->addLine(down,pen);
    scene->addLine(left,pen);
    scene->addLine(right,pen);

}

BreakTheWall::~BreakTheWall()
{
    delete ball;
    delete paddle;
    delete ui;

}
/**
 * Funzione invocata da timerEvent(QTimerEvent *).
 *
 * Controlla un'eventuale collisione con gli altri item della scena.
 * Se c'è una collisione modifica le coordinate di movimento della pallina
 */
void BreakTheWall::collision()
{
    if (ball->collidesWithItem(paddle))
    {
        // Controlla se la pallina colpisce lo spigolo del paddle
        int paddlePos = paddle->x() ;
        int ballPos = ball->x() + 5;
        int bordoL = paddlePos-10;
        int bordoR = paddlePos+25;

        // Collisione con spigolo sinistro
        if (ballPos <= bordoL)
            //Definisco l'angolazione
            ball->setXDir(-2);
        // Collisione con spigolo destro
        if (ballPos >= bordoR)
            //Definisco l'angolazione
            ball->setXDir(2);

        ball->setYDir(-ball->getYdir());
    }

    // Controlla ciclicamente se la pallina collide con ogni singolo mattone
    for (int i=0; i<50; i++)
    {
        if (!brick[i]->destroyed && ball->collidesWithItem(brick[i])){

            // Modifica la direzione e setta destroyed a true

            ball->setYDir(-ball->getYdir());
            brick[i]->destroyed = true;

            //Incremento il contatore di mattoni distrutti

            Brickcount++;

            // Controlla vittoria
            if (Brickcount ==50)
            {
                QMessageBox::information(this,"WINNER","HAI DISTRUTTO IL MURO!!\n COMPLIMENTI");
                killTimer(timeId);
                this->close();
            }

        }
    }
    /*
     *  Controlla se la pallina colpisce la base del rettangolo
     *  In caso affermativo: Game Over
     */
    if (ball->y() >= 50)
    {
        QMessageBox::information(this,"Loser","GAME OVER \nRIPROVA");
        killTimer(timeId);
        this->close();
    }

}
/**
 * Funzione che crea il muro di mattoni.
 */
void BreakTheWall::createWall()
{
    //Inizializzo le variabili che definiscono l'angolo superiore sinistro del muro
    xBrick = -147;
    yBrick = -460;
    for (int i=0;i<50;i++)
    {
            if ( i % 10 ==0)
                //Vado a capo riportando xBrick al valore iniziale
            {
                xBrick= -147;
                yBrick+= 20;
            }

            brick[i] = new Brick;

            scene->addItem(brick[i]);
            brick[i]->xpos=xBrick;
            brick[i]->ypos=yBrick;
            xBrick +=34;
    }
}

/**
 * Funzione che gesisce gli eventi provocati dalla
 * pressione di un tasto
 */
void BreakTheWall::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())

    {

    //Right: Sposta il paddle verso destra
    case Qt::Key_Right:
            {
                if ( paddle->x() >= 145)
                        paddle->setX(155);
                else
                    paddle->moveBy(15,0);
                    break;
            }

    //Left: Sposta il paddle verso sinistra
    case Qt::Key_Left:
            {
                if (paddle->x() <= -145)
                    paddle->setX(-155);
                else
                    paddle->moveBy(-15,0);
                break;
            }

   // Space: Avvia la pallina (settando il timer)
    case Qt::Key_Space:
            {
               if (!running)
               {
                   timeId = startTimer(10);
                   running = true;
                   break;
               }
            }
    }

    update();

}
/**
 * Funzione che periodicamente richiama Ball.move() e collision(),
 * permettendo il movimento della pallina ed il controllo di
 * un eventuale collisione
 */
void BreakTheWall::timerEvent(QTimerEvent *)
{
    ball->move();
    collision();
    update();

    // Aggiorna stato label
    ui->Brk_distrutti->setText(QString::number(Brickcount));
    ui->Brk_rimanenti->setText(QString::number(50 - Brickcount));
}


