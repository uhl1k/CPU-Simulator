project("Simple CPU in C++")
cmake_minimum_required(VERSION 2.8)
set(TARGET cpp-cpu)
add_executable(
    ${TARGET} 
    main.cpp
    cpu.cpp
    clock.cpp
    bus.cpp
    registry.cpp
    program_counter.cpp
    memory.cpp
    alu.cpp
    out.cpp
)

