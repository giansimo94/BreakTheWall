#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QDialog>
#include <src/instructions.h>
#include <src/breakthewall.h>
#include <src/topscores.h>


namespace Ui {
class Menu;
}

/**
 * @brief
 * Visualizzazione del menu
 *
 * Opzioni:
 * - Start game: Inzia una nuova partita
 * - How to play: Istruzioni e comandi del gioco
 * - Top Scores: Visualizzazione dei migliori 10 punteggi
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

    void on_TopScores_clicked();

private:
    Ui::Menu *ui;
    Menu *menu;
    Instructions *istrDial;
    TopScores *Topscores;
};

#endif // MENU_H
