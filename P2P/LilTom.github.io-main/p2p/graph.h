#ifndef GRAPH_H
#define GRAPH_H
# include<QVector>
#include<client.h>
class graph
{

public:
    QVector<QVector<int> > map;
    QVector<client*> vec_client;
    int heigh;
    int length;
    int client_sum;
    graph(){}
    graph(int x,int y,int sum);
};

#endif // GRAPH_H
