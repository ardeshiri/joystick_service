#ifndef MOTOR_MED_H
#define MOTOR_MED_H
#include "Joystick_mediator.h"
#include "Joystick_observer.h"
#include "CPPAMQP.h"


namespace cub{

class Motor_med: public cub::Joystick_observer
{
public:
    Motor_med(arax::CPPAMQP& r);
    void update(const cub::JK_state& s) override;

private:
    int y{0};
    arax::CPPAMQP& rmq_ins;
};

}

#endif // MOTOR_MED_H
