#include "out.hpp"

out::out(bus *bus) : cpu(bus)
{
    
}

out::~out()
{

}

void out::clock_down()
{
    if (do_read)
    {
        data.push_back(cpu->read_bus());
        std::cout << "[OUT] read from bus " << (unsigned int) cpu->read_bus() << "\n";
        do_read = false;
    }
}

void out::clock_up()
{

}

void out::read_from_bus()
{
    this->do_read = true;
}

std::vector<unsigned char> out::get_data()
{
    return data;
}