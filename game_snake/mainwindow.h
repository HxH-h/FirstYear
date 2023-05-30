#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
# include <QMouseEvent>
# include <QPainter>
# include <QKeyEvent>
# include <ctime>
# include <QTimer>
#include <QTime>
#include<QTimerEvent>
# include "snake.h"
#include "gameover.h"
# include<ctime>
# include<QDateTime>
#include<QTimerEvent>
#include<QFileDialog>
#include<QMessageBox>
#include <string>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);
    void begrand();
    void produce();
    void together();
    void writeFile();
private:
    Ui::MainWindow *ui;
    int wid=10;
    int posx;
    int posy;
    int tId;
    QTime time2;
    QString usedTime;
};
#endif // MAINWINDOW_H
