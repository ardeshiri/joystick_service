#include "Motor_med.h"

cub::Motor_med::Motor_med(arax::CPPAMQP& r):rmq_ins{r}
{}

void cub::Motor_med::update(const cub::JK_state& s)
{
    if(s.buttons[11])
    {
        std::vector<std::string> msg{"on@"};
        rmq_ins.send_string(msg, 1, "med", "motor", true, false);
        std::cout<<"motor on"<<std::endl;
    }
    if(s.buttons[10])
    {
        std::vector<std::string> msg{"off@"};
        rmq_ins.send_string(msg, 1, "med", "motor", true, false);
        std::cout<<"motor off"<<std::endl;
    }
    if(s.y < 0)
    {
        if(y != 1)
        {
            std::vector<std::string> msg{"fwd@","fwd@"};
            rmq_ins.send_string(msg, 1, "med", "motor", true, false);
            std::cout<<"forwards"<<std::endl;
            y = 1;
        }
    }
    if(s.y > 0)
    {
        if(y != -1)
        {
            std::vector<std::string> msg{"bwd@","bwd@"};
            rmq_ins.send_string(msg, 1, "med", "motor", true, false);
            std::cout<<"backwards"<<std::endl;
            y = -1;
        }
    }
    if(s.y == 0)
    {
        if(y != 0)
        {
            std::vector<std::string> msg{"stp@","stp@"};
            rmq_ins.send_string(msg, 1, "med", "motor", true, false);
            std::cout<<"stop"<<std::endl;
            y = 0;
        }
    }
}
