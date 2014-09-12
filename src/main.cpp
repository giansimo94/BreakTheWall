#include "src/menu.h"
#include <QApplication>

/**
 * Funzione principale che crea l'applicazione e ne permette
 * la sua visualizzazione e la sua gestione tramite un Menu
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();

    return a.exec();
}
