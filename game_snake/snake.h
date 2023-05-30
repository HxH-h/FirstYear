
#ifndef SNAKE_H
#define SNAKE_H
#include<QKeyEvent>
class Body{
public:
    int bx;
    int by;
    Body(){

    }

};

class Snake
{
public:
    int hx;
    int hy;
    int n;
    double speed;
    int key;
    Body body[100];
    const int width=10;
    Snake(int x, int y);
    int eat(int x,int y);
    void move();
    void getKey(int key);
    void Speed_Up();
    int GameOver();
};

#endif // SNAKE_H
