#ifndef GRAPH_H
#define GRAPH_H
# include<QVector>
#include<client.h>
# include<server.h>
class graph
{

public:
    QVector<QVector<int> > map;
    server* serv;
    QVector<client*> vec_client;
    QVector<int> map_server_To_client;
    int heigh;
    int length;
    int client_sum;
    graph(){}
    graph(int x,int y,int sum);
};

#endif // GRAPH_H
