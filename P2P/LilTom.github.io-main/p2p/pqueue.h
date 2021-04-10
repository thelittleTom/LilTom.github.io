#ifndef PQUEUE_H
#define PQUEUE_H
#include "event.h"
#include"qvector.h"

class PQueue
{
public:
    int size;
    QVector<Event> data;
    Event pop();
    void push(Event);
    int lenth();
    void siftDown(int);
    void popUp(int);
    Event front();
    bool empty();
    PQueue();
};

#endif // PQUEUE_H
