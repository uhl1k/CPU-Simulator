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

#ifndef BUS_H
#define BUS_H

#include <iostream>

class bus
{
    protected:
        unsigned char data;

        bool overflow_flag;
        bool zero_flag;
    
    public:
        bus();
        ~bus();

        char read_bus();
        void write_bus(unsigned char word);

        void set_zero_flag();
        void reset_zero_flag();

        void set_overflow_flag();
        void reset_overflow_flag();
};

#endif
