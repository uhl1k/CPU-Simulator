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

#ifndef OUT_H
#define OUT_H

#include <iostream>
#include <vector>

#include "bus.hpp"
#include "clock_listener.hpp"

class out
{
    private:
        std::vector<unsigned char> data;
        bus *cpu;
        bool do_read = false;
    
    public:
        out(bus *bus);
        ~out();

        void clock_down();
        void clock_up();
        void read_from_bus();

        std::vector<unsigned char> get_data();
};

#endif
