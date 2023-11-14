#ifndef BUS_H
#define BUS_H

#include <iostream>

class bus
{
    protected:
        unsigned char data;

        bool overflow_flag;
        bool zero_flag;
    
    public:
        bus();
        ~bus();

        char read_bus();
        void write_bus(unsigned char word);

        void set_zero_flag();
        void reset_zero_flag();

        void set_overflow_flag();
        void reset_overflow_flag();
};

#endif
