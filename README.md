# CPU Simulator

This is a C++ program that I made for course Programing in C/C++ in winter semester of 2022/2030 academic year on CTU in Prague. It a simulation of a simple CPU. Insparation for this was project made by Ben Eater in which he built CPU using TTL logic. The project can be found at https://eater.net/8bit.

## How to build the program

It is recommended to use `cmake` that is already prepared to build the program. To build the program, clone the project. Then navigate to `src` folder:

```
cd src
```

Here, create a `build` folder to build the project in, so the `src` directory is not mess. Then navigate to this directory:

```
mkdir build
cd build
```

Now we can build the program using `cmake`. Run the following commands:

```
cmake ../
make
```

That's it. You have successfully build the program. You will have executable named `cpp-cpu` in the `build directory`.

## How to run the program

Run the program from command line using

```
./cpp-cpu [-in PROGRAM] [-out OUT] [-mem MEM_DUMP]
```

command. There are several options that change behavior of the program.

* **-in** specifies file with input program. This file should be exactly 16 bytes long. This option is not required althought the simulation will do nothing and program will end with exception because the memory will contain only *NOP* instructions.

* **-out** specifies file to which content of out registry is written after simulation ends.

* **-mem** specifies file to which content of memory is written after simulation ends.

During simulation the program prints to the standard output what it is doig. This can be helpful when debuging programs or to understand the internal functionality.

### Exceptions

Program can end prematurely with two exceptions. First one is that *program counter grew out of memory*. This means the current value in the program counter is bigger than 15 and program does not have a HLT instruction at the end.

Second exception is that *address is out of memory* and this means that memory read address from bus that is bigger than maximum address. This shouldn't really happen unles you modify the microinstructions.

## Example programs

There are six example programs that were used to test the simulation and demostrate the functionality.

### even.mem

Is pushing even numbers starting from 2 to the OUT registry until overflow happens.

```
 0: 42 | LIA 2 | Load number 2 to A registry
 1: 52 | LIB 2 | Load number 2 to B registry
 2: C0 | OUT   | Push content of A registry to OUT registry
 3: 80 | ADD   | Add content of B registry to A registry - add 2 to A registry
 4: B6 | BOF 6 | Jump to address 6 if A had overflown
 5: D2 | JMP 2 | Jump to address 2
 6: 10 | HLT   | End the program
 7: 00 | NOP   |
 ...
 F: 00 | NOP   |
```

### fib.mem

Is pushing fibonacci numbers to the OUT registry until overflow happens.

```
 0: 42 | LIA 0 | Load number 2 to A registry
 1: 52 | LIB 1 | Load number 2 to B registry
 2: C0 | OUT   | Push content of A registry to OUT registry
 3: 80 | ADD   | Add content of B registry to A registry - add 2 to A registry
 4: B6 | BOF 8 | Jump to address 6 if A had overflown
 5: 6F | STA F | Store content of A registry to F address
 6: 3F | LDB F | Load data from address F to B registry
 7: D2 | JMP 2 | Jump to address 2
 8: 10 | HLT   | End the program
 9: 00 | NOP   |
 ...
 F: 00 | NOP   |
```

### over1.mem

Is testing the BOF instruction by adding two big numbers.

```
 0: 2D | LDA D | Load number 200 to A registry
 1: 3D | LDB D | Load number 200 to B registry
 2: 80 | ADD   | Add content of B registry to A registry
 3: B7 | BOF 7 | Jump to address 7 if A had overflown
 4: 2E | LDA E | Load N to A registry
 5: C0 | OUT   | Print N to output
 6: 10 | HLT   | End the program
 7: 2F | LDA F | Load Y to A registry
 8: C0 | OUT   | Print Y to output
 9: 10 | HLT   | End the progam
 A: 00 | NOP   |
 B: 00 | NOP   |
 C: 00 | NOP   |
 D: C8 | data  | 200 in decimal
 E: 4E | data  | letter N
 F: 59 | data  | letter Y
```

### over1.mem

Is testing the BOF instruction by subtracting bigger number from smaller one

```
 0: 45 | LIA 5 | Load number 5 to A registry
 1: 3D | LDB D | Load number 200 to B registry
 2: 90 | SUB   | Subtract content of B registry from A registry
 3: B7 | BOF 7 | Jump to address 7 if A had overflown
 4: 2E | LDA E | Load N to A registry
 5: C0 | OUT   | Print N to output
 6: 10 | HLT   | End the program
 7: 2F | LDA F | Load Y to A registry
 8: C0 | OUT   | Print Y to output
 9: 10 | HLT   | End the progam
 A: 00 | NOP   |
 B: 00 | NOP   |
 C: 00 | NOP   |
 D: C8 | data  | 200 in decimal
 E: 4E | data  | letter N
 F: 59 | data  | letter Y
```

### test.mem

Is testing most of the instructions.

```
 0: 00 | NOP   | 
 1: 2E | LDA E | Load number #4E to A registry
 2: 3F | LDB F | Load number #A6 to B registry
 3: 43 | LIA 3 | Load number 3 to A registry
 4: 54 | LIB 4 | Load number 4 to B registry
 5: 6E | STA E | Store A to address E
 6: 7F | STB F | Store B to address F
 7: 80 | ADD   | Add B to A
 8: 90 | SUB   | Subtract B from A
 9: C0 | OUT   | Print A to output
 A: DD | NOP   |
 B: 00 | NOP   |
 C: 00 | NOP   |
 D: 10 | HLT   | End the program
 E: 4E | data  | number
 F: A6 | data  | number
```

### zero.mem

Is testing functionality of BZE instruction.

```
 0: 45 | LIA 5 | Load number 5 to A registry
 1: 55 | LIB 5 | Load number 5 to B registry
 2: 90 | SUB   | LSubtract B from A
 3: A7 | BZE 7 | Jump to address 7 if result zero
 4: 2E | LDB E | Load letter N to A registry
 5: C0 | OUT   | Print N to output
 6: 10 | HLT   | End of program
 7: 2F | LDB F | ALoad letter Y to A registry
 8: C0 | OUT   | Print Y to output
 9: 10 | HLT   | End of program
 A: 00 | NOP   |
...
 D: 00 | NOP   |
 E: 4E | data  | Letter N
 F: 59 | data  | Letter Y
```

## Creating your own programs

You can write your own program. Use hex editor to create a file that has exactly 16 bytes in length and fill it up with instruction to create your desired program. Available instructions are listed below.

## Architecture

The architecture is very simplified and options of the processor are limited. The biggest limitations are:

* 4 bit address
* 16 bytes of combined program and data memory.
* 15 instructions

The follow diagram shows the block diagram of processor:

* **CPU** is the heart of the simulation. It contains the bus that other parts use to communicate, the flags to controll the run of the program and decoding logic that determins what to do with each instruction.
* **Clock** call alternatively `clock_up()` and `clock_down()` methods that make the processor run.
* **A registry** can load data from the bus and put data back on the bus. It is also used for writing data to the OUT registry and for adding and subtracting.
* **B registry** can load data from the bus and put data back on the bus. It is also used for adding and subtracting.
* **ALU** can sum or subtract values in registries A and B and put the result on the bus setting flags in the proccess.
* **Program counter** stores the address of current instruction. Can load from bus and can increment current value by one.
* **Memory** has a 16 bytes array that can be addressed using 4-bit address. Can load address or data from the bus or output data to the bus.
* **OUT registry** has an array to which stores the data written to the output. Can read data from the bus.

## Instruction set

Each instruction byte consists of two part. The upper four bits are the instruction it self and the bottom four bits are parametere of the instruction. The parameter can be address, data or it might not be used at all. To see what parameter instruction expects see instruction detail.

There are 14 instructions. The number is the HEX value of the instruction (upper 4 bytes) that are followed by parameter or 0. Three letters are human readable representation that is not used by the simulation.

Third and fourth microinstructions are mentioned for instructers if they are not empty. First and second microinstruction are always same and they are:

* Program counter writes current address to the bus and memory loads it as an address.
* Memory outputs data on the address loaded in first microinstruction. This data is loaded by `cpu` class and decoded.

Here are the 14 instructions with two unused instructions also mentioned:

* **0 - NOP** Does nothing. Parameter ignored.
* **1 - HLT** Stops the clock and end the simulation. Parameter ignored.
    * *Third* microinstruction sends signal to clock to stop.
* **2 - LDA** Loads the A registry with value that is at address that is specified as parameter.
    * *Third* microinstruction puts parameter on the bus and memory loads it as an address.
    * *Fourth* microinstruction puts data on the address on the bus and registry A loads it.
* **3 - LDB** Loads the B registry with value that is at address that is specified as parameter.
    * *Third* microinstruction puts parameter on the bus and memory loads it as an address.
    * *Fourth* microinstruction puts data on the address on the bus and registry B loads it.
* **4 - LIA** Loads the A registry with value that is specified as parameter.
    * *Third* microinstruction puts parameter of the instruction on the bus and registry A loads as an value.
* **5 - LIB** Loads the B registry with value that is specified as parameter.
    * *Third* microinstruction puts parameter of the instruction on the bus and registry B loads as an value.
* **6 - STA** Stores content of A registry to address specified as parameter.
    * *Third* microinstruction puts parameter of the instruction on bus and a memory loads it as an address.
    * *Fourth* microinstraction puts value from registry A on the bus and memmory stores it on address loaded in third microinstruction.
* **7 - STB** Stores content of B registry to address specified as parameter.
    * *Third* microinstruction puts parameter of the instruction on bus and a memory loads it as an address.
    * *Fourth* microinstraction puts value from registry B on the bus and memmory stores it on address loaded in third microinstruction.
* **8 - ADD** Sums values in A and B registers and puts the result in A registry. Parameter is ignored.
    * *Third* microinstruction calculates the sum of values in registries A and B and puts it on the bus setting flags in the proccess. Registry A then loads this value.
* **9 - SUB** Subtracts value in registry B from value in registry A and stores the result in registry A.
    * *Third* microinstruction calculates difference of values in registry A and B and puts the result on the bus setting flags in proccess. Registry A then loads the value from bus.
* **A - BZE** If zero flag is set jumps to address specified as parameter. Otherwise does nothing.
    * *Third* microinstruction puts the parameter of the instruction on the bus and program counter loads it but only if the *zero* flag is set. If it is not set it does nothing.
* **B - BOF** If overflow flag is set jumps to address specified as parameter. Otherwise does nothing.
    * *Third* microinstruction puts the parameter of the instruction on the bus and program counter loads it but only if the *overflow* flag is set. If it is not set it does nothing.
* **C - OUT** Writes content of A registry to OUT registry. Parametr ignored.
    * *Third* microinstruction puts value from registry A on the bus and OUT registry stores it.
* **D - JMP** Jumps to a address specified as parameter.
    * *Third* microinstruction puts the parameter of the instruction on the bus and program counter loads it.
* **E** and **F** are currently unassigned and will behave as NOP instruction.

All instructions take exactly 4 clock cycles to executes and some cycles might be wasted. This was done for simplicity.
