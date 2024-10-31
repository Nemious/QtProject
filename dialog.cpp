#include "dialog.h"
#include "ui_dialog.h"
#include "primelist.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(calculate()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calculate() {
    qDebug() << "Function called: " << Q_FUNC_INFO;
    bool isAOK, isBOK;
    int a = ui->lineEditA->text().toInt(&isAOK);
    int b = ui->lineEditB->text().toInt(&isBOK);

    if (!isAOK) {
        QMessageBox::critical(this, "Ошибка", "A должно быть числом");
        return; // Прерывание выполнения функции
    }
    if (!isBOK) {
        QMessageBox::critical(this, "Ошибка", "B должно быть числом");
        return; // Прерывание выполнения функции
    }

    ui->listWidget->clear();

    for (int n : getPrimes(a, b)) {
        ui->listWidget->addItem(QString::number(n));
    }
}

