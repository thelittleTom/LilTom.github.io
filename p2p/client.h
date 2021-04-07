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
    QQueue<int> video_group;
    int N;
    int M;
    int ne;
    position posi;
    int require_time;
    int total_group;
    client();
    client(int n,int m,int xx,int yy);
    client(int n,int m,int xx,int yy,int r,int d);
};

#endif // CLIENT_H
