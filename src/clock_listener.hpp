#ifndef CLOCK_LISTENER_H
#define CLOCK_LISTENER_H

class clock_listener
{
    public:
        virtual void clock_up() = 0;
        virtual void clock_down() = 0;
};

#endif