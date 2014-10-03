#ifndef TOPSCORES_H
#define TOPSCORES_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
#include <QtCore>
#include <QTableView>
#include <src/save_load.h>


namespace Ui {
class TopScores;
}


/**
 * @brief
 * Finestra che visualizza i 10 top scores
 */

class TopScores : public QDialog
{
    Q_OBJECT

public:
    explicit TopScores(QWidget *parent = 0);
    ~TopScores();

private:

    Ui::TopScores *ui;
    QStandardItemModel *model;
    Score Topscores[10];
    Save_Load save_load_t;

    //Funzioni
    void loadTopScores();
    void update_table();

private slots:

    void on_Azzera_clicked();
    void on_Esci_clicked();

};

#endif // TOPSCORES_H
