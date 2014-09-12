#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QDialog>
#include <istructions.h>
#include <breakthewall.h>


namespace Ui {
class Menu;
}

/**
 * Oggetto di tipo QDialog.
 * Permette la visualizzazione del menu
 *
 * Opzioni:
 * - Start game: Inzia una nuova partita
 * - How to play: Istruzioni e comandi del gioco
 * - About: Informazioni su autore e implementazione del codice
 * - Exit: Uscita
 */


class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_StartGame_clicked();

    void on_Exit_clicked();

    void on_HowToPlay_clicked();

    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    Menu *menu;
    Istructions *istrDial;
};

#endif // MENU_H
