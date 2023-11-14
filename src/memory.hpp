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

#ifndef MEMORY_H
#define MEMORY_H

#include <algorithm>
#include <iostream>

#include "bus.hpp"
#include "clock_listener.hpp"

class memory : public clock_listener
{
    private:
        const unsigned char mem_size = 16;

        unsigned char *data;
        unsigned char addr;

        bool do_read_address;
        bool do_read_data;

        bus* cpu;

    public:
        memory(bus *bus);
        ~memory();

        void read_address();
        void write_address();
        
        void read_data();
        void write_data();

        void clock_up();
        void clock_down();

        void load_memory(unsigned char *data, unsigned char size);
        void dump_memory(unsigned char *data, unsigned char size);
        unsigned char memory_size();
};

#endif
