#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "confirmation.h"
#include <QMessageBox>
QString fDir, fName;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Button_GRW_clicked()
{
    Confirmation confirm;
    fDir = "C:/Program Files (x86)/Ubisoft/Ubisoft Game Launcher/games/Tom Clancy's Ghost Recon Wildlands/EasyAntiCheat/EasyAntiCheat_x64.dll";
    if(!QFile(fDir).exists()){
       fDir = QFileDialog::getExistingDirectory(this, "Choose Game Directory","C://",QFileDialog::ShowDirsOnly);
       fDir.append("/Tom Clancy's Ghost Recon Wildlands/EasyAntiCheat/EasyAntiCheat_x64.dll");
    }
    confirm.fileName = fDir;
    confirm.setModal(true);
    confirm.exec();
    qDebug() << QFile::copy(":/exes/bypass/EasyAntiCheat_x64.dll",fDir);
}

void MainWindow::on_Button_SAO_clicked()
{
    Confirmation confirm;
    fDir = "C:/Program Files (x86)/Steam/steamapps/common/SWORD ART ONLINE FATAL BULLET/SAOFB_Launcher.exe";
    if(!QFile(fDir).exists()){
       fDir = QFileDialog::getExistingDirectory(this, "Choose File","C://",QFileDialog::ShowDirsOnly);
       fDir.append("/steamapps/common/SWORD ART ONLINE FATAL BULLET/SAOFB_Launcher.exe");
    }
    qDebug() << QFile(fDir).exists();
    confirm.fileName = fDir;
    confirm.setModal(true);
    confirm.exec();
    qDebug() << QFile::copy(":/exes/bypass/SAOFB_Launcher.exe",fDir);;
}

void MainWindow::on_Button_GRB_clicked()
{


    Confirmation confirm;
    fDir = "C:/Program Files (x86)/Ubisoft/Ubisoft Game Launcher/games/Ghost Recon Breakpoint/GRB_BE.exe";
    if(!QFile(fDir).exists()){
       fDir = QFileDialog::getExistingDirectory(this, "Choose File","C://",QFileDialog::ShowDirsOnly);
       fDir.append("/Ghost Recon Breakpoint/GRB_BE.exe");
    }
    confirm.fileName = fDir;
    confirm.setModal(true);
    confirm.exec();
    QFile::copy(":/exes/bypass/GRB_BE.exe",fDir);
    qDebug() << "Complete";

}

void MainWindow::on_Button_Gears5_clicked()
{

    //QProcess::startDetached("C:/Users/Chris/Documents/CSE_1222/build-Bypass_Manager-Desktop_Qt_5_14_2_MSVC2015_64bit-Release/release/Gears5_EACbypass.exe");
    QProcess::startDetached(QDir::currentPath()+"/Gears5_EACbypass.exe");
    /*qDebug() << QDir::currentPath()+"/Gears5_EACbypass.exe";
    QMessageBox msg;
    msg.setText(QDir::currentPath()+"/Gears5_EACbypass.exe");
    msg.exec();*/

}

void MainWindow::on_pushButton_clicked()
{
    Confirmation confirm;
    fDir = "C:/Program Files (x86)/Steam/steamapps/common/Outlaws of the Old West/Outlaws/Binaries/Win64/Outlaws-Win64-Shipping_BE.exe";
    if(!QFile(fDir).exists()){
       fDir = QFileDialog::getExistingDirectory(this, "Choose File","C://",QFileDialog::ShowDirsOnly);
       fDir.append("/steamapps/common/Outlaws of the Old West/Outlaws/Binaries/Win64/Outlaws-Win64-Shipping_BE.exe");
    }
    qDebug() << QFile(fDir).exists();
    confirm.fileName = fDir;
    confirm.setModal(true);
    confirm.exec();
    qDebug() << QFile::copy(":/exes/bypass/Outlaws-Win64-Shipping_BE.exe",fDir);
}
