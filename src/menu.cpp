#include "src/menu.h"
#include <src/topscores.h>
#include "ui_menu.h"



Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
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
        BreakTheWall *newBTW = new BreakTheWall;
        newBTW->setMaximumSize(1000,1000);
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
    istrDial = new Instructions;
    istrDial->exec();

}

/**
 * Funzione che permette di visualizzare i 10 TopScores
 */

void Menu::on_TopScores_clicked()
{
    Topscores = new TopScores;
    Topscores->exec();
}
