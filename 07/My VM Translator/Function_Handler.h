//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_FUNCTION_HANDLER_H
#define MY_VM_TRANSLATOR_FUNCTION_HANDLER_H

#include <string>
#include <stack>
#include <iostream>
#include "Utils.h"

using namespace std;

class Function_Handler
{
    string current_command;
public:
    explicit Function_Handler(string current_command, ofstream& output_file, vector<string> tokens);
    ~Function_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_FUNCTION_HANDLER_H
