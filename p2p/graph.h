#ifndef GRAPH_H
#define GRAPH_H
# include<QVector>
#include<client.h>
# include<server.h>
class graph
{

public:
    QVector<QVector<int> > map;//0号为服务器，1到100为客户端
    server* serv;
    QVector<client*> vec_client;
    void dfs(int,QVector<int>&,int,QVector<int>&);
    int heigh;
    int length;
    int client_sum;
    graph(){}
    graph(int x,int y,int sum);
};

#endif // GRAPH_H
