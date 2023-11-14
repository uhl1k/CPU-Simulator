#include "registry.hpp"

registry::registry(bus *bus) : cpu(bus), data(0), read_bus(false)
{
    
}

registry::~registry()
{

}

unsigned char registry::value()
{
    return this->data;
}

void registry::read_from_bus()
{
    this->read_bus = true;
}

void registry::write_to_bus()
{
    this->cpu->write_bus(data);
    std::cout << "[REG] write value to bus " << (unsigned int) data << "\n";
}

void registry::load(unsigned char value)
{
    this->data = value;
}

void registry::clock_up()
{

}

void registry::clock_down()
{
    if (this->read_bus)
    {
        data = this->cpu->read_bus();
        std::cout << "[REG] read value from bus " << (unsigned int) data << "\n";
    }

    this->read_bus = false;
}