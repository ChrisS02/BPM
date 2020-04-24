#include "confirmation.h"
#include "ui_confirmation.h"

Confirmation::Confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirmation)
{
    ui->setupUi(this);
}

Confirmation::~Confirmation()
{
    delete ui;
}

void Confirmation::on_buttonBox_accepted()
{
    QFile file(fileName);
    file.rename(fileName + ".bak");
    this -> close();
}

void Confirmation::on_buttonBox_rejected()
{
     this -> close();
     qDebug() << "No";
}
