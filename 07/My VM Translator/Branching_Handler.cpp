//
// Created by Roe on 8/22/2020.
//

#include "Branching_Handler.h"

Branching_Handler::Branching_Handler(string current_command, ofstream &output_file, vector<string>& tokens):
current_command(current_command),tokens(tokens)
{
    string first_word = tokens[0];
    if (first_word == "if-goto")
        handleIfGoto(output_file);
    else if (first_word == "goto")
        handleGoto(output_file);
    else if (first_word == "label")
        handleLabel(output_file);
}

void Branching_Handler::handleIfGoto(ofstream &output_file)
{

}

void Branching_Handler::handleGoto(ofstream &output_file)
{

}

void Branching_Handler::handleLabel(ofstream &output_file)
{

}
