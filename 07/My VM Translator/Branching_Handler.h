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
    string current_command;
    int& current_command_index;
    ofstream & output_file;
    vector<string> tokens;
    vector<string>& lines;
    bool flag_did_jump;
    void handleIfGoto();
    void handleGoto();
    void handleLabel();
public:
    explicit Branching_Handler(string current_command, ofstream& output_file,
                               vector<string>& tokens ,int& current_command_index, vector<string>& lines);
    bool didJump();
    ~Branching_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_BRANCHING_HANDLER_H
