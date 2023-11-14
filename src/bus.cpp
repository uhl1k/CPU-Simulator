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

#include "bus.hpp"

bus::bus() : data(0), zero_flag(false), overflow_flag(false)
{

}

bus::~bus()
{

}

char bus::read_bus()
{
    return this->data;
}

void bus::write_bus(unsigned char word)
{
    this->data = word;
}

void bus::set_overflow_flag()
{
    this->overflow_flag = true;
    std::cout << "[FLAG] overflow flag is set" << "\n";
}

void bus::reset_overflow_flag()
{
    this->overflow_flag = false;
    std::cout << "[FLAG] overflow flag is reset" << "\n";
}

void bus::set_zero_flag()
{
    this->zero_flag = true;
    std::cout << "[FLAG] zero flag is set" << "\n";
}

void bus::reset_zero_flag()
{
    this->zero_flag = false;
    std::cout << "[FLAG] zero flag is reset" << "\n";
}
