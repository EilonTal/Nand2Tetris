//
// Created by Roe on 8/22/2020.
//

#include "Function_Handler.h"
Function_Handler::Function_Handler(string current_command, ofstream& output_file, vector<string> tokens):
current_command(current_command)
{
    string first_word = tokens[0];
    if (first_word == "call")
        handle_call();
    else if (first_word == "function")
        handle_function();
    else if (first_word == "return")
        handle_return();
}

void Function_Handler::handle_call()
{

}

void Function_Handler::handle_function()
{

}

void Function_Handler::handle_return()
{

}
