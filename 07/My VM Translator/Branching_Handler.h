//
// Created by Roe on 8/ a22/2020.
// afa

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
    vector<string> tokens;
    void handleIfGoto(ofstream &output_file);
    void handleGoto(ofstream &output_file);
    void handleLabel(ofstream &output_file);
public:
    explicit Branching_Handler(string current_command, ofstream& output_file, vector<string>& tokens);
    ~Branching_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_BRANCHING_HANDLER_H
