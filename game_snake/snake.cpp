#include "snake.h"
#include "mainwindow.h"

//构造函数，构造蛇的初始状态

Snake::Snake(int x,int y):hx(x),hy(y)
{
    this->n=0;
    this->speed=500;
    int i;
    for(i=0;i<5;i++){
        body[i].bx=hx+width*(i+1);
        body[i].by=hy;
        n++;
    }
    for(i=5;i<100;i++){
        body[i].bx=0;
        body[i].by=0;
    }
}

//获取键盘信息

void Snake::getKey(int key){
    this->key=key;
}

//判断是否吃食物，传递吃的信息，更新数据

int Snake::eat(int x,int y){
    int flag=0;
    if(this->hx==x&&this->hy==y){
        n++;
        flag=1;
    }

    return flag;
}

//移动

void Snake::move(){
    int i;    
    switch(this->key){
        case Qt::Key_Left:
        if(hx-10<=0){
            break;
        }
        body[0].bx=hx;
        body[0].by=hy;
        for(i=n-1;i>0;i--){
            body[i].bx=body[i-1].bx;
            body[i].by=body[i-1].by;

        }
        hx-=width;


        break;

        case Qt::Key_Right:
        if(hx+10>=600){
            break;
        }
        body[0].bx=hx;
        body[0].by=hy;
        for(i=n-1;i>0;i--){
            body[i].bx=body[i-1].bx;
            body[i].by=body[i-1].by;

        }
        hx+=width;
        break;

        case Qt::Key_Up:
        if(hy-10<=0){
            break;
        }
        body[0].bx=hx;
        body[0].by=hy;
        for(i=n-1;i>0;i--){
            body[i].bx=body[i-1].bx;
            body[i].by=body[i-1].by;
        }
        hy-=width;

        break;

        case Qt::Key_Down:
        if(hy+10>=400){
            break;
        }
        body[0].bx=hx;
        body[0].by=hy;
        for(i=n-1;i>0;i--){
            body[i].bx=body[i-1].bx;
            body[i].by=body[i-1].by;

        }
        hy+=width;


        break;

    }
}

//随着得分增速

void Snake::Speed_Up(){
    speed*=0.9;
    qDebug()<<speed;
}

//判定游戏结束

int Snake::GameOver(){
    int flag=0;
    for(int i=0;i<n;i++){
        if(body[i].bx==hx&&body[i].by==hy){
            flag=1;
            break;
        }
    }
    if(hx==0||hy==0||hx==590||hy==390){
        flag=1;
    }
    return flag;
}

