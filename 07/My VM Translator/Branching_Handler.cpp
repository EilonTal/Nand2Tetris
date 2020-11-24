//
// Created by Roe on 8/22/2020.
//

#include "Branching_Handler.h"

Branching_Handler::Branching_Handler(ofstream &output_file, vector<string>& tokens):
tokens(tokens), output_file(output_file)
{
    string first_word = tokens[0];
    if (first_word == "if-goto")
        handleIfGoto();
    else if (first_word == "goto")
        handleGoto();
    else if (first_word == "label")
        handleLabel();
}

void Branching_Handler::handleIfGoto()
{
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "@" << tokens[1] << endl;
    output_file << "D;JNE" << endl;
}

void Branching_Handler::handleGoto()
{
    output_file << "@" << tokens[1] << endl;
    output_file << "0;JMP" << endl;
}

void Branching_Handler::handleLabel()
{
    output_file << "@" << tokens[1] << endl;
}
