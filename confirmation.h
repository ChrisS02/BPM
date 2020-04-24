#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QFileDialog>
#include <QDialog>
#include <QDebug>
#include <QDir>
#include <QFile>

namespace Ui {
class Confirmation;
}

class Confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit Confirmation(QWidget *parent = nullptr);
    ~Confirmation();
QString fileDir,fileName;

private slots:
void on_buttonBox_accepted();

void on_buttonBox_rejected();

private:
    Ui::Confirmation *ui;
};

#endif // CONFIRMATION_H
