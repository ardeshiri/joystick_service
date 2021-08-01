#include "Servo_med.h"

cub::Servo_med::Servo_med(arax::CPPAMQP& r):rmq_ins{r}
{}

void cub::Servo_med::update(const cub::JK_state& s)
{
    std::string cmd{};
    if(s.buttons[9])
    {
        std::vector<std::string> msg{"on@"};
        rmq_ins.send_string(msg, 1, "med", "servo", true, false);
        std::cout<<"servo on"<<std::endl;
        return;

    }
    if(s.buttons[8])
    {
        std::vector<std::string> msg{"off@"};
        rmq_ins.send_string(msg, 1, "med", "servo", true, false);
        std::cout<<"servo off"<<std::endl;
        return;
    }

    float tmpsx = s.x + 100;
    tmpsx = 60.0 + ((tmpsx/200) * 80);
    if(sx != int(tmpsx))
    {
        sx = tmpsx;
        std::string tmpstr{};
        tmpstr += "#";
        tmpstr += "0";
        tmpstr += "^";
        tmpstr += std::to_string(sx);
        cmd += tmpstr;
    }

    float tmpcx = (s.r*-1) + 100;
    tmpcx =((tmpcx/(200))*180);
    if(cx != int(tmpcx))
    {
        cx = tmpcx;
        std::string tmpstr{};
        tmpstr += "#";
        tmpstr += "2";
        tmpstr += "^";
        tmpstr += std::to_string(cx);
        cmd += tmpstr;
    }

    int tmpcy = (cy + s.py/10);
    tmpcy = std::clamp(tmpcy, 0, 180);
    if(cy != tmpcy)
    {
        cy = tmpcy;
        std::string tmpstr{};
        tmpstr += "#";
        tmpstr += "1";
        tmpstr += "^";
        tmpstr += std::to_string(cy);
        cmd += tmpstr;
    }

    if(cmd.length() != 0)
    {
        cmd += "@";
        std::vector<std::string> msg{cmd};
        rmq_ins.send_string(msg, 1, "med", "servo", true, false);
        std::cout<<cmd<<std::endl;
    }
}
