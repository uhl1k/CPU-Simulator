#ifndef MEMORY_H
#define MEMORY_H

#include <algorithm>
#include <iostream>

#include "bus.hpp"
#include "clock_listener.hpp"

class memory : public clock_listener
{
    private:
        const unsigned char mem_size = 16;

        unsigned char *data;
        unsigned char addr;

        bool do_read_address;
        bool do_read_data;

        bus* cpu;

    public:
        memory(bus *bus);
        ~memory();

        void read_address();
        void write_address();
        
        void read_data();
        void write_data();

        void clock_up();
        void clock_down();

        void load_memory(unsigned char *data, unsigned char size);
        void dump_memory(unsigned char *data, unsigned char size);
        unsigned char memory_size();
};

#endif
