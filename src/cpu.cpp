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

#include "cpu.hpp"

cpu::cpu(int argc, char **argv) : read_instruction(false), micro_tick(0), instr(0)
{
    _clock = new cpu_clock(this);
    _a = new registry(this);
    _b = new registry(this);
    _pc = new program_counter(this);
    _m = new memory(this);
    _out = new out(this);
    _alu = new alu(this, _a, _b);

    for (int i = 1; i < argc; i++)
    {
        std::string option(argv[i]);
        // loading memory from file
        if (option == "-in")
        {
            i++;
            std::string filename(argv[i]);
            char buffer[16];
            std::ifstream file(filename);
            file.read(buffer, 16);
            _m->load_memory((unsigned char*) buffer, 16);
        }
        else if (option == "-out")
        {
            // prepare for dumping the output to a file
            i++;
            std::string data_file(argv[i]);
            data_out = data_file;
        }
        else if (option == "-mem")
        {
            // prepare for dumping out the memory
            i++;
            std::string mem_file(argv[i]);
            mem_out = mem_file;
        }
    }
}

cpu::~cpu()
{
    delete _clock;
    delete _a;
    delete _b;
    delete _pc;
    delete _m;
    delete _out;
    delete _alu;
}

void cpu::run()
{
    this->_clock->run();

    // dump out the memory
    if (mem_out != "")
    {
        std::ofstream output( mem_out, std::ios::binary | std::ios::out);
        unsigned char data[_m->memory_size()];
        _m->dump_memory(data, _m->memory_size());
        output.write((char*) data, _m->memory_size());
        output.close();
    }
    // dump out the output
    if (data_out != "")
    {
        std::ofstream output( data_out, std::ios::binary | std::ios::out);
        for (auto ch: _out->get_data())
            output.write((char*) &ch, 1);
        output.close();
    }
}

void cpu::clock_up()
{
    int index = micro_tick;

    // if flags are set add them to the index we will use to find the correct microinstruction
    if (this->zero_flag)
        index |= 1UL << 2;
    if (this->overflow_flag)
        index |= 1UL << 3;

    // chceck bits in microinstruction and decide what to do
    if (0b0000000000000010 & microcode[instr][index])
    {
        this->data = addr;
        std::cout << "[CPU] wrote address to bus " << (unsigned int) addr << "\n";
    }
    if (0b1000000000000000 & microcode[instr][index])
        this->_alu->subtract();
    if (0b0100000000000000 & microcode[instr][index])
        this->_alu->write_to_bus();
    if (0b0010000000000000 & microcode[instr][index])
        this->_clock->stop();
    if (0b0001000000000000 & microcode[instr][index])
        this->read_instruction = true;
    if (0b0000100000000000 & microcode[instr][index])
        this->_m->read_address();
    if (0b0000010000000000 & microcode[instr][index])
        this->_pc->read_from_bus();
    if (0b0000001000000000 & microcode[instr][index])
        this->_m->read_data();
    if (0b0000000100000000 & microcode[instr][index])
        this->_m->write_data();
    if (0b0000000010000000 & microcode[instr][index])
        this->_pc->write_to_bus();
    if (0b0000000001000000 & microcode[instr][index])
        this->_pc->increment();
    if (0b0000000000100000 & microcode[instr][index])
    {
        std::cout << "{A} ";
        this->_a->read_from_bus();
    }
    if (0b0000000000010000 & microcode[instr][index])
    {
        std::cout << "{A} ";
        this->_a->write_to_bus();
    }
    if (0b0000000000001000 & microcode[instr][index])
    {
        std::cout << "{B} ";
        this->_b->read_from_bus();
    }
    if (0b0000000000000100 & microcode[instr][index])
    {
        std::cout << "{B} ";
        this->_b->write_to_bus();
    }
    if (0b0000000000000001 & microcode[instr][index])
        this->_out->read_from_bus();

    // pass the clock tick to all other parts
    this->_a->clock_up();
    this->_b->clock_up();
    this->_pc->clock_up();
    this->_m->clock_up();
    this->_out->clock_up();

    micro_tick = (micro_tick + 1) % 4;
}

void cpu::clock_down()
{
    if (this->read_instruction)
    {
        this->instr = (this->read_bus() & 0b11110000) >> 4;
        this->addr = this->read_bus() & 0b00001111;

        std::cout << "[CPU] read instruction and address from bus " << (unsigned int) instr << " " << (unsigned int) addr << "\n";
    }
    read_instruction = false;

    this->_a->clock_down();
    this->_b->clock_down();
    this->_pc->clock_down();
    this->_m->clock_down();
    this->_out->clock_down();
}
