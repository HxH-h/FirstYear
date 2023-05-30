#include "mainwindow.h"
#include "ui_mainwindow.h"
# include "calcultor.h"
# include <QApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(0);
    ui->lineEdit_2->setEnabled(0);
    ui->lineEdit->setFont(QFont("",14,QFont::ExtraBold));
    ui->lineEdit_2->setFont(QFont("",14,QFont::ExtraBold));
    this->grabKeyboard();

    connect(ui->pushButton_0,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("0");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_1,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("1");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("2");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("3");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("4");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("5");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("6");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("7");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("8");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("9");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_point,&QPushButton::clicked,[=](){
       ui->lineEdit->insert(".");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_plus,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("+");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_sub,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("-");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_mul,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("*");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_div,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("/");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_left,&QPushButton::clicked,[=](){
       ui->lineEdit->insert("(");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_right,&QPushButton::clicked,[=](){
       ui->lineEdit->insert(")");
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_CR,&QPushButton::clicked,[=](){
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
    });
    connect(ui->pushButton_Backspace,&QPushButton::clicked,[=](){
       ui->lineEdit->backspace();
    });
    connect(ui->pushButton_cal,&QPushButton::clicked,[=](){
       ishow();
       ui->lineEdit->clear();
    });
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_0:
        ui->lineEdit->insert("0");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_1:
        ui->lineEdit->insert("1");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_2:
        ui->lineEdit->insert("2");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_3:
        ui->lineEdit->insert("3");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_4:
        ui->lineEdit->insert("4");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_5:
        ui->lineEdit->insert("5");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_6:
        ui->lineEdit->insert("6");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_7:
        ui->lineEdit->insert("7");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_8:
        ui->lineEdit->insert("8");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_9:
        ui->lineEdit->insert("9");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Backspace:
        ui->lineEdit->backspace();
        break;
        case Qt::Key_Delete:
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Plus:
        ui->lineEdit->insert("+");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Minus:
        ui->lineEdit->insert("-");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Asterisk:
        ui->lineEdit->insert("*");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Slash:
        ui->lineEdit->insert("/");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_ParenLeft:
        ui->lineEdit->insert("(");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_ParenRight:
        ui->lineEdit->insert(")");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Period:
        ui->lineEdit->insert(".");
        ui->lineEdit_2->clear();
        break;
        case Qt::Key_Enter:
        ishow();
        ui->lineEdit->clear();
        break;
        case Qt::Key_Return:
        ishow();
        ui->lineEdit->clear();
        break;
        default:
        QApplication::beep();
        break;
    }
    return ;
}
MainWindow::~MainWindow()
{
    delete ui;
}

