#include "src/menu.h"
#include <src/topscores.h>
#include "ui_menu.h"



Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    setMaximumSize(500,500);
    setGeometry(450,150,500,500);
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

/**
 * Visualizzazione della schermata del gioco
 */
void Menu::on_StartGame_clicked()
{
        BreakTheWall *newBTW = new BreakTheWall(this);
        newBTW->setMaximumSize(600,700);
        newBTW->setGeometry(450,100,600,700);
        newBTW->exec();

}

/**
 * Esce dal gioco
 */

void Menu::on_Exit_clicked()
{
    this->close();
}

/**
 * Visualizzazione istruzioni e comandi del gioco
 */

void Menu::on_HowToPlay_clicked()
{
    istrDial = new Instructions(this);
    istrDial->setMaximumSize(550,510);
    istrDial->exec();

}

/**
 * Funzione che permette di visualizzare i 10 TopScores
 */

void Menu::on_TopScores_clicked()
{
    Topscores = new TopScores(this);
    Topscores->setMaximumSize(255,420);
    Topscores->exec();
}
