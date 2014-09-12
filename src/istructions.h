#ifndef ISTRUCTIONS_H
#define ISTRUCTIONS_H

#include <QDialog>



namespace Ui {
class Istructions;
}

/**
 * Oggetto di tipo QDialog.
 * Permette la visualizzazione delle istruzioni e dei comandi
 * dall'interno del menu
 */

class Istructions : public QDialog
{
    Q_OBJECT

public:
    explicit Istructions(QWidget *parent = 0);
    ~Istructions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Istructions *ui;
};

#endif // ISTRUCTIONS_H
