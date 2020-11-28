//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_FUNCTION_HANDLER_H
#define MY_VM_TRANSLATOR_FUNCTION_HANDLER_H

#include <string>
#include <stack>
#include <iostream>
#include <fstream>
#include "Utils.h"

using namespace std;

class Function_Handler
{
    ofstream& output_file;
    vector<string>& tokens;
    int & label_index;
    void handle_call();
    void handle_function();
    void handle_return();
    int get_new_label_index();
public:
    explicit Function_Handler( ofstream& output_file, vector<string>& tokens, int & label_index);
    ~Function_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_FUNCTION_HANDLER_H
