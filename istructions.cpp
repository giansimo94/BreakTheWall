#include "istructions.h"
#include "ui_istructions.h"



Istructions::Istructions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Istructions)
{
    ui->setupUi(this);
}

Istructions::~Istructions()
{
    delete ui;
}

void Istructions::on_pushButton_clicked()
{
    this->close();
}
