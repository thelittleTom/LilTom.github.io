#include "pqueue.h"
#include "event.h"
#include<QDebug>
void swapEvent(Event& a,Event& b){
    Event tmp=a;
    a=b;
    b=tmp;
}

int parent(int k){
    return (k-1)/2;
}

int leftChild(int k){
    return k*2+1;
}

int rightChild(int k){
    return k*2+2;
}

bool PQueue::empty(){
    return size==0;
}

Event PQueue::front(){
    if(size>0)
        return data[0];
    return Event(-1,-1,-1);//错误返回值
}

Event PQueue::pop(){
    if(size==0)
        return Event(-1,-1,-1);//错误返回值
    Event ret=data[0];
    data[0]=data[size-1];
    --size;
    siftDown(0);
    return ret;
}

void PQueue::push(Event newEvent){
//    qDebug()<<size<<" in push"<<endl;
    if(data.size()==size)
        data.push_back(newEvent);
    ++size;
    popUp(size-1);
}

int PQueue::lenth(){
    return size;
}

//pos:当前节点位置
void PQueue::siftDown(int pos){
    if(leftChild(pos)>=size&&rightChild(pos)>=size)
        return;
    int next=pos;
    if(leftChild(pos)<size&&data[leftChild(pos)].time<data[next].time){
        next=leftChild(pos);
    }
    if(rightChild(pos)<size&&data[rightChild(pos)].time<data[next].time){
        next=rightChild(pos);
    }
    if(next!=pos){
        swapEvent(data[next],data[pos]);
        siftDown(next);
    }
}

void PQueue::popUp(int pos){
    if(pos==0||data[parent(pos)].time<data[pos].time){
        return;
    }
    swapEvent(data[parent(pos)],data[pos]);
    popUp(parent(pos));
}

PQueue::PQueue()
{
    size=0;
    data.clear();
}
