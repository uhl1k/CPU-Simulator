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

#include "alu.hpp"

alu::alu(bus *bus, registry *a, registry *b) : cpu(bus), a(a), b(b), do_subtract(false)
{

}

alu::~alu()
{

}

void alu::write_to_bus()
{
    if (this->do_subtract)
    {
        if ((this->a->value() < this->b->value()))
            this->cpu->set_overflow_flag();
        else
            this->cpu->reset_overflow_flag();

        this->cpu->write_bus(this->a->value() - this->b->value());
        do_subtract = false;
        std::cout << "[ALU] subtracting wrote to bus " << (unsigned int)(this->a->value() - this->b->value()) << "\n";
    }
    else
    {
        int tmp = this->a->value() + this->b->value();
        if (tmp > 255)
            this->cpu->set_overflow_flag();
        else
            this->cpu->reset_overflow_flag();

        this->cpu->write_bus(this->a->value() + this->b->value());
        std::cout << "[ALU] adding wrote to bus " << (unsigned int) (this->a->value() + this->b->value()) << "\n";
    }


    if (this->cpu->read_bus() == 0)
        this->cpu->set_zero_flag();
    else
        this->cpu->reset_zero_flag();
}

void alu::subtract()
{
    this->do_subtract = true;

}

void alu::clock_down()
{

}

void alu::clock_up()
{

}
