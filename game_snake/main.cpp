#include "mainwindow.h"
#include"log.h"
#include <QApplication>
#include "snake.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    class log l;
    l.show();
    if(l.exec()==QDialog::Accepted){
        w.show();
        return a.exec();
    }else{
        return 0;
    }
}
