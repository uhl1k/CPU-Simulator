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

#ifndef PROGRAM_COUNTER_H
#define PROGRAM_COUNTER_H

#include <iostream>

#include "registry.hpp"

class program_counter : public registry
{
    private:
        bool do_incerement = false;

    public:
        program_counter(bus *bus);

        void increment();
        void write_to_bus();
        void clock_down();
};  

#endif
