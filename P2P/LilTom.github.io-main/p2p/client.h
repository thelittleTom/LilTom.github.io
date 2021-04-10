#ifndef CLIENT_H
#define CLIENT_H
# include"QQueue"
struct position{
    int x;
    int y;
    position(int xx=0,int yy=0){
        x=xx;
        y=yy;
    }
};

class client
{  
public:
    int videoWatched;//记录看过的视频数量
    QQueue<int> video_group;
    bool isPlaying;//表示是否正在播放
    bool finishPlaying;//表示当前客户端已完成播放，防止在离散事件模拟中重复播放(如果已完成播放，则不会重新播放)
    int N;
    int M;
    int ne;
    position posi;
    int require_time;
    int total_group;//客户端需要看多少个视频数据块
    int timeToConsume;//消耗一个视频块所需的时间
    client();
    client(int n,int m,int xx,int yy);
    client(int n,int m,int xx,int yy,int r,int d);
    bool canPlay();//检查当前客户端能否播放视频，即是否拥有连续的数据块
};

#endif // CLIENT_H
