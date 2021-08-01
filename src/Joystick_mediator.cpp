#include "Joystick_mediator.h"
#include <thread>
#include "JK_state.h"

cub::Joystick_mediator::Joystick_mediator(int j, std::chrono::milliseconds i):stop_f{false}, jstk{j}, interval{i}, observers{}
{}

cub::Joystick_mediator::~Joystick_mediator()
{}

void cub::Joystick_mediator::main_loop()
{
    cub::JK_state jks{};
    while(!stop_f)
    {
        sf::Joystick::update();
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::X))
        {
            jks.x = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::X);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::Y))
        {
            jks.y = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::Y);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::Z))
        {
            jks.z = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::Z);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::R))
        {
            jks.r = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::R);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::U))
        {
            jks.u = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::U);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::V))
        {
            jks.v = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::V);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::PovX))
        {
            jks.px = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::PovX);
        }
        if(sf::Joystick::hasAxis(jstk, sf::Joystick::Axis::PovY))
        {
            jks.py = sf::Joystick::getAxisPosition(jstk, sf::Joystick::Axis::PovY);
        }
        for(unsigned int i = 0 ; i < sf::Joystick::getButtonCount(jstk); i++)
        {
            jks.buttons[i] = sf::Joystick::isButtonPressed(jstk, i);
        }
        for(auto ptr: observers)
        {
            ptr-> update(jks);
        }
        std::this_thread::sleep_for(interval);
    }
}

void cub::Joystick_mediator::register_observer(cub::Joystick_observer& o)
{
    observers.push_back(&o);
}

void cub::Joystick_mediator::stop()
{
    stop_f = true;
}

int cub::find_connected_joystick()
{
    using namespace std::chrono;
    for(int j = 0 ; j < 3; j++)
        for(int i = 0; i < 5; i++)
        {
            sf::Joystick::update();
            if(sf::Joystick::isConnected(i))
                return i;
            std::this_thread::sleep_for(10ms);
        }
    return -1;
}
