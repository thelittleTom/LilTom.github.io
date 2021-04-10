#include "graph.h"
# include<algorithm>
#include<math.h>
# include<QDebug>
graph::graph(int l,int h,int sum)
{
    heigh=h;
    length=l;
    client_sum=sum;
    QVector<QVector<int>> test;
    //随机生成点的n(缓存快数量）,m（连续播放的条件）,位置
    for(int i=0;i<client_sum;i++){
        int n=rand()%11+10;
        int m=rand()%6+5;
        int x,y;
        while(1){
             x=rand()%(length-10)+10;
             y=rand()%(heigh-10)+10;

            if(std::find(test.begin(),test.end(),QVector<int>(x,y))==test.end()){
                test.push_back(QVector<int>(x,y));
                break;
            }
        }
        client* p=new client(n,m,x,y);
        vec_client.push_back(p);
    }
    //随机生成服务器的位置
    int x,y;
    while(1){
        x=rand()%(length-10)+10;
        y=rand()%(heigh-10)+10;

       if(std::find(test.begin(),test.end(),QVector<int>(x,y))==test.end()){
           test.push_back(QVector<int>(x,y));
           serv=new  server(x,y);
           break;
       }
    }
    //随机生成客户端与服务器的连边
    for(int i=0;i<client_sum;i++){
       if(rand()%2){
           int d;
           int dx=vec_client[i]->posi.x-serv->posi.x;
           int dy=vec_client[i]->posi.y-serv->posi.y;
           d=std::sqrt(dx*dx+dy*dy);
           map_server_To_client[i]=d;
       }
       else{
           map_server_To_client[i]=-1;
       }
    }
    //随机生成每一个点的五条边
    for(int i=0;i<client_sum;i++){
        QVector<int> t;
        for(int j=0;j<client_sum;j++){
            t.push_back(-1);
        }
       map.push_back(t);
    }
    for(int i=0;i<client_sum;i++){
        while(vec_client[i]->ne<5){
            int j=rand()%100;
            if(vec_client[j]->ne<5){
                int dx=vec_client[i]->posi.x-vec_client[j]->posi.x;
                int dy=vec_client[i]->posi.y-vec_client[j]->posi.y;
                map[i][j]=std::sqrt(dx*dx+dy*dy);
                map[j][i]=std::sqrt(dx*dx+dy*dy);
                vec_client[i]->ne++;
                vec_client[j]->ne++;
            }
        }
    }
}
