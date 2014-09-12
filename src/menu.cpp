#include "src/menu.h"
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
 * Funzione senza parametri in ingresso, invocata alla pressione
 * del rispettivo tasto.
 *
 * Visualizzazione della schermata del gioco
 */
void Menu::on_StartGame_clicked()
{
    menu = new Menu;
    BreakTheWall *newBTW = new BreakTheWall;
    newBTW->setMaximumSize(1000,1000);
    newBTW->exec();
}

/**
 * Funzione senza parametri in ingresso, invocata alla pressione
 * del rispettivo tasto.
 *
 * Esce dal gioco
 */

void Menu::on_Exit_clicked()
{
    this->close();
}

/**
 * Funzione senza parametri in ingresso, invocata alla pressione
 * del rispettivo tasto.
 *
 * Visualizza istruzioni e comandi del gioco

 */

void Menu::on_HowToPlay_clicked()
{
    istrDial = new Istructions;
    istrDial->exec();

}

/**
 * Info sul gioco e sul creatore.
 */

void Menu::on_pushButton_clicked()
{
    QMessageBox::information(this,"About","BREAK THE WALL: \nA game created by GIANPAOLO SIMONE using QT-libraries");
}
