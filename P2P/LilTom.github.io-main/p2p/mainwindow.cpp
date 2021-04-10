#include "mainwindow.h"
#include "ui_mainwindow.h"
# include<QDebug>
#include "pqueue.h"
#include<QTime>
#include<QtGlobal>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    point_num=100;
    resize(1500,1000);
    gra=new graph(this->size().width(),this->size().height(),point_num);
    curTime=0;//时间初始化为0
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//随机数种子设置
    timeToGoOff=300;
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

//Event 事件构造函数参数顺序 type id time
void MainWindow::simulation(){
    while(!eventList.empty()&&eventList.front().time==curTime){
        Event cur_event=eventList.pop();
        if(cur_event.Event_type==0){//0表示有新的客户端开始播放
            int curClient=cur_event.id;//当前处理的客户端的id
            gra->vec_client[curClient]->isPlaying=true;//标记当前客户端开始播放,如果开始播放，则需定期检查邻居节点，请求需要的视频数据块
            int nextTime=(qrand()%4)+curTime;//随机生成 下一个客户端开始请求播放的时间
            int nextClient=qrand()%gra->client_sum;
            while(nextClient==curClient||gra->vec_client[nextClient]->finishPlaying==true){
                nextClient=qrand()%gra->client_sum;//随机生成下一个开始播放的客户端。不能是当前客户端，也不能是已经完成播放的客户端
            }
            if(nextTime<timeToGoOff)//判断是否超过下班时间
                eventList.push(Event(cur_event.Event_type,nextClient,nextTime));//下一个客户端请求播放事件加入队列
        }
        else{//客户端消耗视频块事件
            int curClient=cur_event.Event_type;//当前处理的客户端的id
            gra->vec_client[curClient]->videoWatched++;//消耗了一个视频块。
            if(gra->vec_client[curClient]->total_group==gra->vec_client[curClient]->videoWatched){//看完的视频块已经等于请求观看的视频块个数，完成播放
                gra->vec_client[curClient]->finishPlaying=true;//完成播放
                gra->vec_client[curClient]->isPlaying=false;
            }
        }
    }
}



