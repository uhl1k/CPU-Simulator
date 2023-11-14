#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

#include "clock_listener.hpp"

class cpu_clock
{
    private:
        clock_listener *_listener;
        int tick;
        bool running;

    public:
        cpu_clock(clock_listener *listener);
        ~cpu_clock();

        void run();
        void stop();
};

#endif
