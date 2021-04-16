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
    //map初始化为-1
    for(int i=0;i<client_sum+1;i++){
        QVector<int> t;
        for(int j=0;j<client_sum+1;j++){
            t.push_back(-1);
        }
       map.push_back(t);
    }
    //0号服务器与客户端
    for(int count=0;count<5;count++){
        while(1){
            int j=rand()%(client_sum)+1;
            if(map[0][j]<0){
                int dx=serv->posi.x-vec_client[j-1]->posi.x;
                int dy=serv->posi.y-vec_client[j-1]->posi.y;
                map[0][j]=std::sqrt(dx*dx+dy*dy);
                map[j][0]=std::sqrt(dx*dx+dy*dy);
                break;
            }
        }
    }
    //随机生成每一个点的五条边
    for(int i=1;i<client_sum+1;i++){
        while(vec_client[i-1]->ne<5){
            int j=rand()%(client_sum)+1;
            if(vec_client[j-1]->ne<5&&map[i][j]<0){
                int dx=vec_client[i-1]->posi.x-vec_client[j-1]->posi.x;
                int dy=vec_client[i-1]->posi.y-vec_client[j-1]->posi.y;
                map[i][j]=std::sqrt(dx*dx+dy*dy);
                map[j][i]=std::sqrt(dx*dx+dy*dy);
                vec_client[i-1]->ne++;
                vec_client[j-1]->ne++;
            }
        }
    }
    //防止生成连通分量
    QVector<int> grouping(client_sum+1,0);
    QVector<int> vis(client_sum+1,0);
    int begin=0;
    int index=0;
    do{

        int i;
        for( i=0;i<client_sum+1;i++){
            if(grouping[i]==0) {
                //更新下一轮dfs信息
                int b=begin;
                begin=i;
                index++;
                vis[begin]=1;
                grouping[begin]=index;
                dfs(begin,grouping,index,vis);

                //将两个连通分量连接起来
                if(b==i){
                    int tmpx;
                    int tmpy;
                    if(b==0) tmpx=serv->posi.x,tmpy=serv->posi.y;
                    else tmpx=vec_client[b-1]->posi.x,tmpy=vec_client[b-1]->posi.y;
                    int dx=tmpx-vec_client[i-1]->posi.x;
                    int dy=tmpy-vec_client[i-1]->posi.y;
                    map[b][i]=std::sqrt(dx*dx+dy*dy);
                    map[i][b]=std::sqrt(dx*dx+dy*dy);
                }


                break;
            }
        }
        if(i==client_sum+1) break;
    }while(1);
}
void graph::dfs(int begin,QVector<int> & grouping,int index,QVector<int>& vis){
    for(int j=0;j<client_sum+1;j++){
        if(vis[j]==0&&j!=begin&&map[begin][j]>0){
            grouping[j]=index;
            vis[j]=1;
            dfs(j,grouping,index,vis);
        }
    }
}
