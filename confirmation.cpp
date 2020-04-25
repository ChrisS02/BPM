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

bool Confirmation::hashIsEqual(QByteArray fileHash){
     QFile file(fileName);
     qDebug() << fileName;
     file.open(QFile::ReadOnly);
     QCryptographicHash sha(QCryptographicHash::Sha256);
     sha.addData(&file);
     file.close();
     qDebug() << sha.result().toHex()<< "\n" << fileHash;
     if(sha.result().toHex() == fileHash){
     ui -> bypassCBox -> setChecked(false);
     ui -> bypassCBox -> setEnabled(false);
     ui -> defaultCBox -> setChecked(true);
     }
     else{
         ui -> defaultCBox -> setChecked(false);
         ui -> defaultCBox -> setEnabled(false);
         ui -> bypassCBox -> setChecked(true);
     }
     return sha.result() == fileHash;
}

void Confirmation::on_buttonBox_accepted()
{   QFile file(fileName);
    if(ui -> bypassCBox -> isChecked()){

        file.rename(fileName + ".bak");
        QFile::copy(bypassDir,fileName);
        this -> close();
    }
    if(ui -> defaultCBox -> isChecked()){
        file.setPermissions(QFile::ReadOther | QFile::WriteOther);
        file.remove();
        file.rename(fileName+".bak",fileName);
        this -> close();
    }
}

void Confirmation::on_buttonBox_rejected()
{
     this -> close();
     qDebug() << "No";
}

