#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QDialog>

namespace Ui {
class Instructions;
}

/**
 * @brief
 * Finestra che visualizza i comandi del gioco
 */
class Instructions : public QDialog
{
    Q_OBJECT

public:
    explicit Instructions(QWidget *parent = 0);
    ~Instructions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Instructions *ui;
};

#endif // INSTRUCTIONS_H
