#include "mainwindow.h"
#include<time.h>
#include <QApplication>
# include<QDebug>
#include "pqueue.h"
#include "event.h"





int main(int argc, char *argv[])
{

    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//Event 事件构造函数参数顺序 type id time
//    eventList.push(Event(0,4,6));
//    eventList.push(Event(0,4,3));
//    eventList.push(Event(0,4,4));
//    eventList.push(Event(0,4,9));
//    eventList.push(Event(0,4,1));
//    eventList.push(Event(0,4,12));
//    eventList.push(Event(0,4,2));
//    eventList.push(Event(0,4,5));
//    while(!eventList.empty()){
//        Event cur=eventList.pop();
//        qDebug()<<cur.time;
//    }
    return a.exec();
}
