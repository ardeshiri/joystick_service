#ifndef SERVO_MED_H
#define SERVO_MED_H
#include "Joystick_mediator.h"
#include "Joystick_observer.h"
#include "CPPAMQP.h"


namespace cub{

class Servo_med: public cub::Joystick_observer
{
public:
    Servo_med(arax::CPPAMQP& r);
    void update(const cub::JK_state& s) override;

private:
    int cx{90};
    int cy{90};
    int sx{-1000};

    arax::CPPAMQP& rmq_ins;
};

}


#endif // SERVO_MED_H
