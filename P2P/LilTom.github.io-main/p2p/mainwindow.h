#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
# include<QPainter>
#include<graph.h>
#include "pqueue.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int curTime; //记录当前的时间
    PQueue eventList;//储存即将要发生的事件
    int timeToGoOff;//记录下班时间，如果下一个要开始播放的客户端的时间超过下班时间，则不再开始播放

    void simulation();//每1秒进行一次事件的模拟；


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    graph* gra;
    int point_num;
protected:
    void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOW_H
