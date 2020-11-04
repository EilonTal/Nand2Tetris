cmake_minimum_required(VERSION 3.17)
project(My_VM_Translator)

set(CMAKE_CXX_STANDARD 20)

add_executable(My_VM_Translator main.cpp Command_Handler.cpp Command_Handler.h Logical_And_Arithmetic_Handler.cpp Logical_And_Arithmetic_Handler.h Memory_Access_Handler.cpp Memory_Access_Handler.h Branching_Handler.cpp Branching_Handler.h Function_Handler.cpp Function_Handler.h Utils.cpp Utils.h)