#include "mainwindow.h"
#include "ui_mainwindow.h"
# include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    point_num=100;
    resize(1500,1000);
    gra=new graph(this->size().width(),this->size().height(),point_num);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent * ){
    //画点与画连边
     QPainter painter(this);
     for(int i=0;i<point_num;i++){
         painter.drawRect(gra->vec_client[i]->posi.x,gra->vec_client[i]->posi.y, 2, 2);
     }
     for(int i=0;i<point_num;i++){
         for(int j=0;j<point_num;j++){
             if(gra->map[i][j]>0){
                 painter.drawLine(gra->vec_client[i]->posi.x, gra->vec_client[i]->posi.y, gra->vec_client[j]->posi.x,gra->vec_client[j]->posi.y);
             }
         }
     }
}

