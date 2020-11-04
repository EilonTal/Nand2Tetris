//
// Created by Roe on 8/19/2020.
//

#include "A_Command_Handler.h"

A_Command_Handler::A_Command_Handler(string command, int *counter_variable_index_ptr, map<string, int>& symbol_table):
command(command), counter_variable_index_ptr(counter_variable_index_ptr), symbol_table_ptr(&symbol_table)
{
}

string A_Command_Handler::toBinary(int n)
{
    string binary;
    while (n != 0)
    {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
}

string A_Command_Handler::get_A_Dest_Binary()
{
    string name = command.substr(1, command.size() - 1);
    int num_command;
    try
    {
        num_command = stoi(name);
    }
    catch (exception & e)
    {
        // new variable
        if (symbol_table_ptr->find(name) == symbol_table_ptr->end())
        {
            symbol_table_ptr->insert(pair<string,int>(name, *counter_variable_index_ptr));
            num_command = *counter_variable_index_ptr;
            (*counter_variable_index_ptr)++;
        }
        else
            num_command = (*symbol_table_ptr)[name];
    }
    return toBinary(num_command);
}

