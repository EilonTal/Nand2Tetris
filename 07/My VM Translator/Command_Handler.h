//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_COMMAND_HANDLER_H
#define MY_VM_TRANSLATOR_COMMAND_HANDLER_H

#include <fstream>


#include "Function_Handler.h"
#include "Logical_And_Arithmetic_Handler.h"
#include "Memory_Access_Handler.h"
#include "Branching_Handler.h"
#include <filesystem>

class Command_Handler
{
    string current_command;
    string file_name_without_suffix;
    ifstream * input_file;
    ofstream * output_file;
    bool isCommandArithmeticOrLogic(string first_word);
    bool isCommandMemoryAccess(string first_word);
    bool isCommandBranch(string first_word);
    bool isCommandFunction(string first_word);
public:
    explicit Command_Handler(string path_str, ifstream &input_file, ofstream & output_file);
    bool isThereAnotherCommand();
    void advance();
    ~Command_Handler();
};




#endif //MY_VM_TRANSLATOR_COMMANDS_HANDLER_H
