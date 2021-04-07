#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
# include<QPainter>
#include<graph.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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
