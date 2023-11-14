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

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

#include "clock_listener.hpp"

class cpu_clock
{
    private:
        clock_listener *_listener;
        int tick;
        bool running;

    public:
        cpu_clock(clock_listener *listener);
        ~cpu_clock();

        void run();
        void stop();
};

#endif
