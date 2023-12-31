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

#include "memory.hpp"

memory::memory(bus *bus) : cpu(bus), do_read_address(false), do_read_data(false)
{
    this->data = new unsigned char[this->mem_size];

    for (int i = 0; i < this->mem_size; i++)
        this->data[i] = 0;
}

memory::~memory()
{
    delete[] data;
}

void memory::read_address()
{
    this->do_read_address = true;
}

void memory::write_address()
{
    this->cpu->write_bus(this->addr);
}

void memory::read_data()
{
    this->do_read_data = true;
}

void memory::write_data()
{
    this->cpu->write_bus(this->data[this->addr]);
    std::cout << "[MEM] wrote data to bus " << (unsigned int) data[addr] << "\n";
}

void memory::clock_up()
{

}

void memory::clock_down()
{
    if (this->do_read_address)
    {
        this->addr = this->cpu->read_bus();
        if (addr >= mem_size)
            throw "Address is out of memory!";
        std::cout << "[MEM] read address from bus " << (unsigned int) addr << "\n";
    }
    if (this->do_read_data)
    {
        this->data[this->addr] = this->cpu->read_bus();
        std::cout << "[MEM] read data from bus " << (unsigned int) data[addr] << "\n";
    }

    this->do_read_address = false;
    this->do_read_data = false;
}

void memory::load_memory(unsigned char *data, unsigned char size)
{
    for (unsigned char i = 0; i < std::min(size, this->mem_size); i++)
        this->data[i] = data[i];
}

void memory::dump_memory(unsigned char *data, unsigned char size)
{
    for (unsigned char i = 0; i < std::min(size, this->mem_size); i++)
        data[i] = this->data[i];
}

unsigned char memory::memory_size()
{
    return this->mem_size;
}
