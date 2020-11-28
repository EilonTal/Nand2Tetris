//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_BRANCHING_HANDLER_H
#define MY_VM_TRANSLATOR_BRANCHING_HANDLER_H

#include <string>
#include <stack>
#include <iostream>
#include "Utils.h"
#include <fstream>

using namespace std;

class Branching_Handler
{
    ofstream & output_file;
    vector<string> tokens;
    void handleIfGoto();
    void handleGoto();
    void handleLabel();
public:
    explicit Branching_Handler(ofstream& output_file, vector<string>& tokens);
    ~Branching_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_BRANCHING_HANDLER_H
