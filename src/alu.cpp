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