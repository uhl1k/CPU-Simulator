/*  Simulator of 8-bit CPU
    Copyright (C) 2023  uhl1k

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
