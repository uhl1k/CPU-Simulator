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
