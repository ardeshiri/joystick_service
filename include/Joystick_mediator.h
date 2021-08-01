#ifndef JOYSTICK_MEDIATOR_H
#define JOYSTICK_MEDIATOR_H
#include <chrono>
#include <SFML/Window/Joystick.hpp>
#include <bitset>
#include <vector>
#include "Joystick_observer.h"

namespace cub
{



class Joystick_mediator
{
public:
    Joystick_mediator(int,std::chrono::milliseconds);
    ~Joystick_mediator();
    void main_loop();
    void register_observer(cub::Joystick_observer&);
    void stop();

protected:

private:
    bool stop_f;
    int jstk;
    std::chrono::milliseconds interval;
    std::vector<cub::Joystick_observer*> observers;
};

int find_connected_joystick();

}
#endif // JOYSTICK_MEDIATOR_H
