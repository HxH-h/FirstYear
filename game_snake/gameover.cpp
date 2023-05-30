#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    //游戏结束显示界面

    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=]{
        close();
    });
}

GameOver::~GameOver()
{
    delete ui;
}
