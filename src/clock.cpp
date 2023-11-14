#include "clock.hpp"

cpu_clock::cpu_clock(clock_listener *listener) : _listener(listener), running(false), tick(0)
{

}
cpu_clock::~cpu_clock()
{
    
}

void cpu_clock::run()
{
    this->running = true;

    while (this->running)
    {
        std::cout << "[CLOCK] tick " << (int) tick << "\n";
        this->_listener->clock_up();
        this->_listener->clock_down();
        this->tick++;
    }
}

void cpu_clock::stop()
{
    this->running = false;
    std::cout << "[CLOCK] stopping" << "\n";
}
