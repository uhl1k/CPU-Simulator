#ifndef OUT_H
#define OUT_H

#include <iostream>
#include <vector>

#include "bus.hpp"
#include "clock_listener.hpp"

class out
{
    private:
        std::vector<unsigned char> data;
        bus *cpu;
        bool do_read = false;
    
    public:
        out(bus *bus);
        ~out();

        void clock_down();
        void clock_up();
        void read_from_bus();

        std::vector<unsigned char> get_data();
};

#endif
