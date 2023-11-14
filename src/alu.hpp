#ifndef ALU_H
#define ALU_H

#include "bus.hpp"
#include "clock_listener.hpp"
#include "registry.hpp"

class alu : clock_listener
{
    private:
        bool do_subtract;

        bus *cpu;
        registry *a;
        registry *b;
    
    public:
        alu(bus *bus, registry *a, registry *b);
        ~alu();

        void write_to_bus();
        void subtract();

        void clock_up();
        void clock_down();
};

#endif
