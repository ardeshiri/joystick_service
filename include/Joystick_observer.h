#ifndef JOYSTICK_OBSERVER_H
#define JOYSTICK_OBSERVER_H
#include "JK_state.h"
namespace cub
{

class Joystick_observer
{
public:
    virtual void update(const cub::JK_state& s) = 0;
    virtual ~Joystick_observer() {}
};

}
#endif // JOYSTICK_OBSERVER_H
