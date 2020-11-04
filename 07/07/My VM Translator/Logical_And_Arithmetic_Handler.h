//
// Created by Roe on 8/22/2020.
//

#ifndef MY_VM_TRANSLATOR_LOGICAL_AND_ARITHMETIC_HANDLER_H
#define MY_VM_TRANSLATOR_LOGICAL_AND_ARITHMETIC_HANDLER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Utils.h"
using namespace std;

class Logical_And_Arithmetic_Handler
{
    string current_command;
public:
    explicit Logical_And_Arithmetic_Handler(string current_command, ofstream &output_file, vector<string> tokens);
    void handleAdd(ofstream &output_file);
    void handleSub(ofstream &output_file);
    void handleNeg(ofstream &output_file);
    void handleEq(ofstream &output_file);
    void handleGt(ofstream &output_file);
    void handleLt(ofstream &output_file);
    void handleAnd(ofstream &output_file);
    void handleOr(ofstream &output_file);
    void handleNot(ofstream &output_file);
    ~Logical_And_Arithmetic_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_LOGICAL_AND_ARITHMETIC_HANDLER_H
