#ifndef REGISTRY_H
#define REGISTRY_H

#include <iostream>

#include "bus.hpp"
#include "clock_listener.hpp"

class registry : clock_listener
{
    protected:
        unsigned char data;
        bus *cpu;

        bool read_bus;

    public:
        registry(bus *bus);
        ~registry();

        unsigned char value();

        void read_from_bus();
        void write_to_bus();
        void load(unsigned char value);

        void clock_up();
        void clock_down();
};

#endif
