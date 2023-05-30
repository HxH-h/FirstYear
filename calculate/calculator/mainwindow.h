#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
# include <qpushbutton.h>
# include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void ishow();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
