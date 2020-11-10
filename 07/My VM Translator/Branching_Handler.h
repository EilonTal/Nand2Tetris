//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_BRANCHING_HANDLER_H
#define MY_VM_TRANSLATOR_BRANCHING_HANDLER_H

#include <string>
#include <stack>
#include <iostream>
#include "Utils.h"

using namespace std;

class Branching_Handler
{
    string current_command;
    int current_command_index;
    vector<string> tokens;
    void handleIfGoto(ofstream &output_file);
    void handleGoto(ofstream &output_file);
    void handleLabel(ofstream &output_file);
public:
    explicit Branching_Handler(string current_command, ofstream& output_file, vector<string>& tokens);
    bool didJump();
    int getNewCommandIndex();
    ~Branching_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_BRANCHING_HANDLER_H
