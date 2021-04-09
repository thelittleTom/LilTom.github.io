#include "client.h"

client::client()
{
     ne=0;
     videoWatched=0;
}
client::client(int n,int m,int xx,int yy,int r,int d){
    videoWatched=0;
    N=n;
    M=m;
    ne=0;
    posi=position(xx,yy);
    require_time=r;
    total_group=d;
}
client::client(int n,int m,int xx,int yy){
    videoWatched=0;
    N=n; ne=0;
    M=m;
    posi=position(xx,yy);
}
