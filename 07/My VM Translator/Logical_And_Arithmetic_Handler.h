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
    int & label_index;
    ofstream & output_file;
public:
    explicit Logical_And_Arithmetic_Handler(ofstream & output_file, vector<string> tokens, int & label_index);
    void handleAdd();
    void handleSub();
    void handleNeg();
    void handleEq();
    void handleGt();
    void handleLt();
    void handleAnd();
    void handleOr();
    void handleNot();
    ~Logical_And_Arithmetic_Handler() = default;
};


#endif //MY_VM_TRANSLATOR_LOGICAL_AND_ARITHMETIC_HANDLER_H
