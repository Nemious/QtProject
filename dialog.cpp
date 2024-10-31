#include "dialog.h"
#include "ui_dialog.h"
#include "primelist.h"

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
    int a = ui->lineEditA->text().toInt();
    int b = ui->lineEditB->text().toInt();

    ui->listWidget->clear();


    for (int n : getPrimes(a, b)) {
        ui->listWidget->addItem(QString::number(n));
    }
}

