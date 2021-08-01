#include <iostream>
#include "Joystick_mediator.h"
#include "Joystick_observer.h"
#include "CPPAMQP.h"
#include "Servo_med.h"
#include "Motor_med.h"
#include <algorithm>
using namespace std;
using namespace std::chrono;


int main()
{

    arax::CPPAMQP rmq{"192.168.1.10",
                      5672,
                      500000};
    rmq.connect_normal("/",
                       "user",
                       "password");

    cub::Motor_med m{rmq};
    cub::Servo_med s{rmq};

    auto js = cub::find_connected_joystick();
    cub::Joystick_mediator jm{js, 150ms};
    jm.register_observer(s);
    jm.register_observer(m);
    jm.main_loop();

    return 0;
}
