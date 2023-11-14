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
