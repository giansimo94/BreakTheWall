/**
 * @mainpage
 * Libreria grafica utilizzata : QT\n
 * IDE utilizzato: QT Creator\n
 *
 * La struttura del codice si basa sui tre oggetti principali del gioco, implementati nelle rispettive classi:
 *
 *
 * Ball\n
 * Paddle\n
 * Brick\n
 *
 * \n
 * Le classi Save_Load e TopScores permettono la gestione,la visualizzazione e il caricamento/salvataggio dei punteggi\n
 *
 * La Gestione del gioco avviene all'interno di BreakTheWall
 *
 * @author Gianpaolo Simone
 */

#include "src/breakthewall.h"
#include "ui_breakthewall.h"
#include <QDebug>
#include <ctime>


/**
 * Funzione che inizializza le variabili
 * e crea la scena aggiungendo tutte le componenti/oggetti
 */
BreakTheWall::BreakTheWall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BreakTheWall)
{
    ui->setupUi(this);

    // Nascondo la finestra del menu
    parent->setVisible(false);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Inizializza le variabili
    Missilecount = 0;
    Brickcount= 0;
    Bonuscount = 0;
    Points = 0;
    extraPoints = 0;
    super_ball = false;
    move_wall = false;
    running = false;
    fire_mode = false;

    qsrand(time(0));

    /*
     * Controllo esistenza del file di salvataggio:
     * se esiste carico i dati, altrimenti creo il file
     * dopo averlo inizializzato
     */

    if (!QFile::exists("BestScores.o"))
        {
            inizializza(TopScores);
            save_load.save(TopScores);
        }
    else
        save_load.load(TopScores);

    // Inizializza le label
    ui->Brk_distrutti->setText(QString::number(Brickcount));
    ui->Brk_rimanenti->setText(QString::number(50 - Brickcount));
    ui->Punti->setText(QString::number(0));

    // Crea e setta la scena
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //Crea il muro
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

    /*
     * Collego il segnale timeout del timer alla funzione endBonusTime()
     */

    connect(&timer,SIGNAL(timeout()), this, SLOT(endBonusTime()));
}

BreakTheWall::~BreakTheWall()
{
    delete ball;
    delete paddle;
    delete ui;

}

/**
 * Invocata quando la finestra viene chiusa, rende visibile la finestra del menu.
 */
void BreakTheWall::closeEvent(QCloseEvent *){
    parentWidget()->setVisible(true);
}


/**
 * @brief Setta le variabili a false
 *
 * Funzione chiamata al segnale timeout del time che
 * termina tutti gli effetti dovuti ai bonus.
 *
 */

void BreakTheWall::endBonusTime()
{
    super_ball = false;
    move_wall = false;
    fire_mode = false;
}

/**
 * @brief
 * Controlla un'eventuale collisione all'interno della scena.
 *
 * Funzione invocata da timerEvent(QTimerEvent *).
 */
void BreakTheWall::check_collision()
{
    // Controlla una collisione del paddle con un bonus
    for (int i=0; i < Bonuscount; i++)
    {
        if (bonus[i]->visible && bonus[i]->collidesWithItem(paddle))
        {
           // Start del timer (3000 msec)
           timer.start(3000);
           bonus[i]->visible = false;

           // Controllo del colore del bonus per settare
           // la variabile booleana corretta
           check_colore(bonus[i]);
        }
    }

    // Controlla una collisione del paddle con la pallina
    if (ball->collidesWithItem(paddle))
    {
        extraPoints = 0;

        // Controlla se la pallina colpisce lo spigolo del paddle
        qreal paddlePos = paddle->x() + 22.5;
        qreal ballPos = ball->x() + 23;
        qreal bordoL = paddlePos - 22.5;
        qreal bordoR = paddlePos + 22.5;


        // Collisione con spigolo sinistro
         if (ballPos <= bordoL + 7.5)
             //Definisco l'angolazione
             ball->setXDir(-2);

         // Collisione con spigolo destro
         if (ballPos >= bordoR - 5)
             //Definisco l'angolazione
             ball->setXDir(2);
         ball->setYDir(-ball->getYdir());
    }

    // Controllo di una possibile collisione con ciascun brick
    for (int i=0; i<50; i++)
    {
        // Controllo collisione missile/brick

        for (int j=0; j < Missilecount; j++)
        {
            if (!brick[i]->destroyed && missile[j]->visible && brick[i]->collidesWithItem(missile[j]))
            {
                missile[j]->visible = false;
                brick[i]->destroyed = true;
                Brickcount++;
                Points+=30;

                // Aggiorno le label
                ui->Brk_distrutti->setText(QString::number(Brickcount));
                ui->Brk_rimanenti->setText(QString::number(50 - Brickcount));
                ui->Punti->setText(QString::number(Points));

            }
        }

        // Controllo collisione pallina/brick
        if (!brick[i]->destroyed && ball->collidesWithItem(brick[i]))
        {
            qreal ballPos = ball->x() + 23;
            qreal ballL = ballPos - 5;
            qreal ballR = ballPos + 5;
            qreal bordoL = brick[i]->xpos ;
            qreal bordoR = brick[i]->xpos + 30;

            /*
             *  Setto le coordinate considerando il caso particolare degli spigoli
             *  nel caso in cui superball non sia attiva
             */
            if (!super_ball && (ballR <= bordoL + 2 || ballL >= bordoR - 2 ))
            {
                ball->setXDir(-ball->getXdir());
            }

            else
            {
                if (!super_ball)
                        ball->setYDir(-ball->getYdir());
            }

                brick[i]->destroyed = true;
                extraPoints++;

                //Incremento il contatore di mattoni distrutti ed il punteggio

                Brickcount++;
                Points+= 50 + 75*extraPoints;

            /*
             *  Se la condizione dell'if è vera, creo il bonus, lo rendo visibile
             *  e ne setto la posizione
             */

            if ((Brickcount % 5)==0)
            {
                bonus[Bonuscount] = new BonusItem;
                scene->addItem(bonus[Bonuscount]);

                bonus[Bonuscount]->visible = true;
                bonus[Bonuscount]->set_coord(brick[i]->xpos + 60 ,brick[i]->ypos + 23 );
                Bonuscount++;
            }



            // Aggiorna stato label
            ui->Brk_distrutti->setText(QString::number(Brickcount));
            ui->Brk_rimanenti->setText(QString::number(50 - Brickcount));
            ui->Punti->setText(QString::number(Points));
        }
    }

    // Controlla vittoria
    if (Brickcount ==50)
    {
        Points+=500;
        QMessageBox::information(this,"WINNER","HAI DISTRUTTO IL MURO!!\n COMPLIMENTI");
        killTimer(timeId);
        this->close();

        name = get_name();
        check_update_TopScore(TopScores,Points,10,name);
        save_load.save(TopScores);
     }

    // Controllo Game Over
    if (ball->y() >= 50 || check_wall_collision())
    {
        QMessageBox::information(this,"Loser","GAME OVER!!!! \n RIPROVA");
        killTimer(timeId);
        this->close();

        name = get_name();
        check_update_TopScore(TopScores,Points,10,name);
        save_load.save(TopScores);
    }
}

/**
 *  Funzione che crea il muro di mattoni
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
 * Sposta il muro verso il basso
 * @param wall
 */

void BreakTheWall::muovi_muro(Brick *wall[])
{
    for (int i=0; i<50; i++)
    {
        wall[i]->moveBy(0,0.3);
    }

}

/**
 * Controlla che il muro non abbia raggiunto una certa altezza
 * @return
 */

bool BreakTheWall::check_wall_collision()
{
    for (int i=0; i<50; i++)
    {
        if (brick[i]->destroyed && brick[i]->y() >= 400)
        {
           return true;
        }
    }

    return false;

}
/**
 * Inizializza la struttura TopScore
 * @param TopScores
 */

void BreakTheWall::inizializza(Score TopScores[])
{
    for (int i=0; i < 10; i++)
    {
        TopScores[i].POINTS = 0;
        strcpy(TopScores[i].Nome, "nDisp");
    }
}

/**
 * Funzione utilizzata per ricevere in input il nome dell'utente.
 * @return Puntatore alla stringa
 */

char* BreakTheWall::get_name()
{
    QString stringa;
    do
    {
        stringa = QInputDialog::getText(this,"Insert name","Inserisci il tuo nome");
    }
        while (stringa.contains(" ") || stringa.size() >=20 || stringa.size()<=0);
    QByteArray ByArr = stringa.toLatin1();
    return ByArr.data();
}

/**
 * Controlla che il punteggio sia nella Top 10:
 * in caso affermativo la aggiorna
 * @param TopScores : Array di oggetti Score
 * @param points : Punteggio Ottenuto
 * @param nEle : Numero di elementi dell'array
 * @param name : Nome dell'utente
 */

void BreakTheWall::check_update_TopScore(Score TopScores[],int points,int nEle, char* name)
{
    // Controllo che il punteggio sia all'interno della Top 10
    int i;
    for ( i=0; i < nEle && points < TopScores[i].POINTS ; i++)
        ;

    for (int j= nEle-1 ; j > i; j--)
    {
        TopScores[j].POINTS = TopScores[j-1].POINTS;
        strcpy(TopScores[j].Nome,TopScores[j-1].Nome);
    }

    strcpy(TopScores[i].Nome,name);
    TopScores[i].POINTS = points;
}
/**
 * @brief
 * Controlla il colore del Bonus e setta la variabile corrispondente
 * @param BItem
 */

void BreakTheWall::check_colore(BonusItem *BItem)
{

    switch (BItem->col_corrente){

    case 0:     //giallo

        {
            super_ball = true;
            break;
        }

    case 1:     //blu

        {
            move_wall = true;
            break;
        }

    case 2:     //rosso

        {
            fire_mode = true;
            break;
        }


    default:

            break;

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
                if (running)
                {
                    if ( paddle->x() >= 145)
                            paddle->setX(155);
                    else
                        paddle->moveBy(15,0);
                }

                break;
            }

    //Left: Sposta il paddle verso sinistra
    case Qt::Key_Left:
            {
                if (running)
                {
                    if (paddle->x() <= -145)
                        paddle->setX(-155);
                    else
                        paddle->moveBy(-15,0);
                }

                break;
            }

   // Space: Avvia la pallina (settando il timer)
    case Qt::Key_Space:
            {
               if (!running)
               {
                   timeId = startTimer(10);
                   running = true;  
               }

               break;
            }
    // Tasto F: Spara
    case Qt::Key_F:
            {
               if ( Missilecount!=100 && fire_mode == true && running == true)
                {
                    int XposPaddle = paddle->x();
                    int YposPaddle = paddle->y();

                    missile[Missilecount] = new Missile;
                    missile[Missilecount]->setPos(XposPaddle + 15 ,YposPaddle );
                    scene->addItem(missile[Missilecount]);

                    missile[Missilecount]->visible = true;
                    Missilecount++;
                }

                break;

            }
    // Tasto P: Pausa
    case Qt::Key_P:
            {
                killTimer(timeId);
                running = false;
                break;
            }


    }
    update();
}

/**
 * Funzione timer che permette il movimento degli oggetti della scena
 * e controlla le collisioni
 */

void BreakTheWall::timerEvent(QTimerEvent *)
{
    ball->move();
    for (int i=0; i< Missilecount; i++)
    {
        if (missile[i]->visible)
            missile[i]->move();
    }
    for (int i=0; i < Bonuscount; i++)
    {
        if (bonus[i]->visible)
            bonus[i]->move_down();
    }

    if (move_wall)
        muovi_muro(brick);
    check_collision();
    update();
}


