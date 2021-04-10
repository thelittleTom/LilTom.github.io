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
    isPlaying=finishPlaying=false;//默认一开始不请求播放视频,也没有完成播放
    timeToConsume=2;//将消耗一个视频块的时间设置为2s
}
client::client(int n,int m,int xx,int yy){
    videoWatched=0;
    N=n; ne=0;
    M=m;
    posi=position(xx,yy);
    isPlaying=finishPlaying=false;//默认一开始不请求播放视频,也没有完成播放
    timeToConsume=2;//将消耗一个视频块的时间设置为2s
}

bool client::canPlay(){
    return true;//待完善
}
