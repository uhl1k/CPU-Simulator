#include "program_counter.hpp"

program_counter::program_counter(bus *bus) : registry(bus)
{
    data = 0;
}

void program_counter::increment()
{
    this->do_incerement = true;
}

void program_counter::clock_down()
{
    if (this->read_bus)
    {
        this->data = this->cpu->read_bus();
        std::cout << "[PC] read address from bus " << (unsigned int) data << "\n";
    }
    if (this->do_incerement)
    {   
        this->data ++;
        std::cout << "[PC] incremented to " << (unsigned int) data << "\n";
    }

    this->read_bus = false;
    this->do_incerement = false;
}

void program_counter::write_to_bus()
{
    if (data > 15)
            throw "Program counter grew out of memory! Use HLT instruction to stop the program before end.";
    this->cpu->write_bus(data);
    std::cout << "[PC] wrote to bus " << (unsigned int) data << "\n";
}