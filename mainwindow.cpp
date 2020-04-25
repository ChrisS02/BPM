#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "confirmation.h"
#include <QMessageBox>
QString fDir, fName;
QByteArray bypassHash;


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
    if(QFile(fDir).exists()){
    confirm.bypassDir = ":/exes/bypass/EasyAntiCheat_x64.dll";
    confirm.fileName = fDir;
    confirm.hashIsEqual(QByteArray("40d3be5c4a156e5c9a7e7bdcad1b2768256ec7c06194a09cb5fc292fc8405e42"));
    confirm.setModal(true);
    confirm.exec();
    }
}

void MainWindow::on_Button_SAO_clicked()
{
    Confirmation confirm;
    fDir = "C:/Program Files (x86)/Steam/steamapps/common/SWORD ART ONLINE FATAL BULLET/SAOFB_Launcher.exe";
    if(!QFile(fDir).exists()){
       fDir = QFileDialog::getExistingDirectory(this, "Choose File","C://",QFileDialog::ShowDirsOnly);
       fDir.append("/steamapps/common/SWORD ART ONLINE FATAL BULLET/SAOFB_Launcher.exe");
    }
    confirm.bypassDir = ":/exes/bypass/SAOFB_Launcher.exe";
    confirm.fileName = fDir;
    confirm.hashIsEqual(QByteArray("6b34a9cd8027c591d54f4c1129291c0a1b9be04bb03dc58334cfd2082a2992b9"));
    confirm.setModal(true);
    confirm.exec();
}

void MainWindow::on_Button_GRB_clicked()
{

    Confirmation confirm;
    fDir = "C:/Program Files (x86)/Ubisoft/Ubisoft Game Launcher/games/Ghost Recon Breakpoint/GRB_BE.exe";
    if(!QFile(fDir).exists()){
       fDir = QFileDialog::getExistingDirectory(this, "Choose File","C://",QFileDialog::ShowDirsOnly);
       fDir.append("/Ghost Recon Breakpoint/GRB_BE.exe");
    }
    confirm.bypassDir = ":/exes/bypass/GRB_BE.exe";
    confirm.fileName = fDir;
    confirm.hashIsEqual(QByteArray("5447a7a9f2ef3efaa0cd1addafde7e9a34f44d0946b2ceb9aa66150d8f17221e"));
    confirm.setModal(true);
    confirm.exec();

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
    confirm.bypassDir = ":/exes/bypass/Outlaws-Win64-Shipping_BE.exe";
    confirm.fileName = fDir;
    confirm.hashIsEqual(QByteArray("9fc2e60ca57833141ad5ad7b9b3364bc2827405636b60cff6d1d9a812cc574aa"));
    confirm.setModal(true);
    confirm.exec();
}
