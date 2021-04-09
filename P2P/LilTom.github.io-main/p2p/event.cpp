#include "event.h"

Event::Event()
{
    id=Event_type=time=-1;
}
Event::Event(int t_type,int t_id,int t_time):Event_type(t_type),id(t_id),time(t_time){}

