#ifndef EVENT_H
#define EVENT_H


class Event
{
public:
    int Event_type;//表示事件发生的类型，0表示新客户端请求播放，1表示客户端消耗视频数据块
    int id;//标记哪个客户端
    int time;//发生的时间
    Event();
    Event(int ,int,int );
};

#endif // EVENT_H
