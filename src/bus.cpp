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