#include "mainwindow.h"
#include "ui_mainwindow.h"

//创建蛇

Snake snake(500,100);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //设置主窗口部分属性

    ui->setupUi(this);
    ui->lineEdit->setEnabled(0);
    ui->pushButton_pause->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_quit->setFocusPolicy(Qt::NoFocus);
    ui->label_2->setText(QString("得分：%1").arg(snake.n));

    //退出游戏确认

    connect(ui->pushButton_quit,&QPushButton::clicked,this,[=](){
            if(QMessageBox::question(this,tr("退出"),tr("确认退出？"),QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok){
                 this->close();
            }
    });

    //设置初始食物坐标，和时间

    posx=100;
    posy=200;
    QTimer *timer=new QTimer(this);  
    time2.setHMS(0,0,0);

    //设置定时控制蛇的移动，正常计时
    //并且控制游戏的开始与暂停

    connect(timer,&QTimer::timeout,[=]{
        static int num=0;
        snake.move();
        ui->label->setText(QString("坐标：（%1,%2）").arg(snake.hx).arg(snake.hy));
        int gameflag=snake.GameOver();
        if(gameflag){
            qDebug()<<"game over";
            this->writeFile();
            GameOver g;
            g.setModal(true);
            g.show();
            g.exec();
            this->close();
        }
        int flag=snake.eat(posx,posy);
        if(flag){
            srand(time(0));
            posx=rand()%570+10;
            posy=rand()%370+10;
            posx-=posx%10;
            posy-=posy%10;
            snake.Speed_Up();

            timer->start(snake.speed);
        }
        num++;
        ui->label_2->setText(QString("得分：%1").arg(snake.n-5));
        MainWindow::update();       
    });

        connect(ui->pushButton_pause,&QPushButton::clicked,[=]{
            static bool flag=false;
            if(flag==false){
                tId=startTimer(1000);
                ui->pushButton_pause->setText("暂停");
                flag=true;
            }else{
                killTimer(tId);
                ui->pushButton_pause->setText("开始");
                flag=false;
            }
        });
        connect(ui->pushButton_pause,&QPushButton::clicked,[=]{
            static bool flag=false;
            if(flag==false){
                timer->start(snake.speed);
                ui->pushButton_pause->setText("暂停");
                flag=true;
            }else{
                timer->stop();
                ui->pushButton_pause->setText("开始");
                flag=false;
            }
        });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//画蛇，画食物，画边界
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter paint(this);
    paint.setClipRect(0,0,600,400);
    QPen pen;
    QPen pen1;
    QPen pen2;
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    pen2.setWidth(3);
    pen2.setColor(Qt::black);
    pen1.setColor(Qt::black);
    pen1.setWidth(3);
    pen.setColor(Qt::black);
    pen.setWidth(this->wid);
    paint.setPen(pen);
    paint.drawLine(0,400,600,400);
    paint.setPen(pen1);
    paint.setBrush(brush);
    paint.drawRect(snake.hx,snake.hy,10,10);
    paint.drawRect(posx,posy,10,10);
    paint.setBrush(Qt::NoBrush);
    paint.setPen(pen2);
    for(int i=0;i<snake.n;i++){
        paint.drawRect(QRect(snake.body[i].bx,snake.body[i].by,10,10));
    }
}

//获取键盘事件

void MainWindow::keyPressEvent(QKeyEvent *event){
    snake.getKey(event->key());
}

//记录游戏，写入数据

void MainWindow::writeFile(){    
    QFile file("../game/record.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray input=file.readAll();
    QString str=QString(input);
    QStringList list=str.split(" ");
    file.close();
    if(list[1].toInt()>=(snake.n-5)){
        return ;
    }else{
        file.open(QIODevice::WriteOnly|QIODevice::Truncate);
        QString output=this->usedTime+" "+QString::number(snake.n-5)+"\n";
        file.write(output.toUtf8());
        file.close();
    }


}

//定时器

void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==tId){
        time2=time2.addSecs(1);
        this->usedTime=time2.toString("hh:mm:ss");
        ui->lineEdit->setText(time2.toString("hh:mm:ss"));
    }
}


