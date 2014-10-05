#include "src/topscores.h"
#include "ui_topscores.h"


TopScores::TopScores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TopScores)
{
    ui->setupUi(this);


    model = new QStandardItemModel;

    // Definisco numero di righe e colonne della tabella

    model->setColumnCount(2);
    model->setRowCount(10);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Score")));

    ui->tableView->setModel(model);

    loadTopScores();

}

/**
 * Aggiorna la tabella con i dati correnti
 */

void TopScores::update_table()
{
    for (int i=0; i<10; i++)
        {
            model->setItem(i,0,new QStandardItem(QString(Topscores[i].Nome)));
            model->setItem(i,1,new QStandardItem(QString::number(Topscores[i].POINTS)));
        }
}

TopScores::~TopScores()
{
    delete ui;
}

/**
 * Caricamento dei dati
 */

void TopScores::loadTopScores()
{

    save_load_t.load(Topscores);
    update_table();

}

/**
 * Azzero tutta la tabella e salvo i dati nel file
 */

void TopScores::on_Azzera_clicked()
{
    for (int i=0; i<10; i++)
    {
        qstrcpy(Topscores[i].Nome, "nDisp");
        Topscores[i].POINTS = 0;
    }
    update_table();
    save_load_t.save(Topscores);
}

/**
 * Esci
 */

void TopScores::on_Esci_clicked()
{
    close();
}
