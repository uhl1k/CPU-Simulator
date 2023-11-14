#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include <iostream>

#include "registry.hpp"

class program_counter : public registry
{
    private:
        bool do_incerement = false;

    public:
        program_counter(bus *bus);

        void increment();
        void write_to_bus();
        void clock_down();
};  

#endif
