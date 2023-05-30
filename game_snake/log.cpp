#include "log.h"
#include "ui_log.h"
#include <QPushButton>
log::log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log)

{   //载入游戏，显示历史最高得分

    ui->setupUi(this);
    ui->lineEdit->setEnabled(0);
    ui->lineEdit_2->setEnabled(0);
    connect(ui->pushButton_in,&QPushButton::clicked,this,&QDialog::accept);
    connect(ui->pushButton_out,&QPushButton::clicked,this,&QDialog::close);
    QFile file("../game/record.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray input=file.readAll();
    QString str=QString(input);
    QStringList list=str.split(" ");
    qDebug()<<list;
    ui->lineEdit->setText(list[0]);
    ui->lineEdit_2->setText(list[1]);
    file.close();
}

log::~log()
{
    delete ui;
}
