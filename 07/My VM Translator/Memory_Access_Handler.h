//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_MEMORY_ACCESS_HANDLER_H
#define MY_VM_TRANSLATOR_MEMORY_ACCESS_HANDLER_H

#include <string>
#include <stack>
#include <iostream>
#include <fstream>
#include "Utils.h"

using namespace std;

class Memory_Access_Handler
{
    string memory_segment;
    string file_name_without_suffix;
    ofstream &output_file;
    int num_cell;
public:
    explicit Memory_Access_Handler(ofstream& output_file, string file_name_without_suffix, vector<string> tokens);
    void handlePop();
    void handlePush();
    ~Memory_Access_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_MEMORY_ACCESS_HANDLER_H
