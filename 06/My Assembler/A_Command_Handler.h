//
// Created by Roe on 8/19/2020.
//

#ifndef MY_ASSEMBLER_A_COMMAND_HANDLER_H
#define MY_ASSEMBLER_A_COMMAND_HANDLER_H

#include <string>
#include <map>
using namespace std;

class A_Command_Handler
{
    map <string , int>* symbol_table_ptr;
    int * counter_variable_index_ptr;
    string command;
    string toBinary(int n);
public:
    explicit A_Command_Handler(string command, int * counter_variable_index_ptr, map <string , int>& symbol_table);
    string get_A_Dest_Binary();
    ~A_Command_Handler() = default;
};


#endif //MY_ASSEMBLER_A_COMMAND_HANDLER_H
