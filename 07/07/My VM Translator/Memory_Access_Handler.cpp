//
// Created by Roe on 8/22/2020.
//

#include "Memory_Access_Handler.h"

Memory_Access_Handler::Memory_Access_Handler(string current_command,
                                            ofstream & output_file,string file_name_without_suffix, vector<string> tokens):
current_command(current_command), file_name_without_suffix(file_name_without_suffix)
{
    string first_word =tokens[0];
    memory_segment = tokens[1];
    num_cell = atoi(tokens[2].c_str());
    if (first_word == "push")
        handlePush(output_file);
    else if (first_word == "pop")
        handlePop(output_file);
}

void Memory_Access_Handler::handlePop(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    if (memory_segment == "local" || memory_segment == "argument" ||
    memory_segment == "this" || memory_segment == "that")
    {
        if (memory_segment == "local")
            output_file << "@LCL" << endl;
        if (memory_segment == "argument")
            output_file << "@ARG" << endl;
        if (memory_segment == "this")
            output_file << "@THIS" << endl;
        if (memory_segment == "that")
            output_file << "@THAT" << endl;
        output_file << "A = M" << endl;
        for (int i = 0; i < num_cell; i++)
        {
            output_file << "A = A + 1" << endl;
        }
    }
    if (memory_segment == "temp")
    {
        output_file << "@5" << endl;
        for (int i = 0; i < num_cell; i++)
        {
            output_file << "A = A + 1" << endl;
        }
    }
    // no const pop
    if (memory_segment == "static")
    {
        output_file << "@" << file_name_without_suffix << "." << num_cell << endl;
    }
    if (memory_segment == "pointer")
    {
        if (num_cell == 0) // this
        {
            output_file << "@THIS" << endl;
        }
        if (num_cell == 1) // that
        {
            output_file << "@THAT" << endl;
        }
    }
    output_file << "M = D" << endl;
}

void Memory_Access_Handler::handlePush(ofstream &output_file)
{
    if (memory_segment == "local" || memory_segment == "argument" ||
        memory_segment == "this" || memory_segment == "that")
    {
        if (memory_segment == "local")
            output_file << "@LCL" << endl;
        if (memory_segment == "argument")
            output_file << "@ARG" << endl;
        if (memory_segment == "this")
            output_file << "@THIS" << endl;
        if (memory_segment == "that")
            output_file << "@THAT" << endl;
        output_file << "D = M" << endl;
        output_file << "@" << num_cell << endl;
        output_file << "A = D + A" << endl;
    }
    if (memory_segment == "temp")
    {
        output_file << "@5" << endl;
        for (int i = 0; i < num_cell; i++)
        {
            output_file << "A = A + 1" << endl;
        }
    }
    if (memory_segment == "static")
    {
        output_file << "@" << file_name_without_suffix << "." << num_cell << endl;
    }
    if (memory_segment == "pointer")
    {
        if (num_cell == 0) // this
        {
            output_file << "@THIS" << endl;
        }
        if (num_cell == 1) // that
        {
            output_file << "@THAT" << endl;
        }
    }
    if (memory_segment == "constant")
    {
        output_file << "@" << num_cell << endl;
        output_file << "D = A" << endl;
    }
    else
    {
        output_file << "D = M" << endl;
    }
    output_file << "@SP" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;
    output_file << "@SP" << endl;
    output_file << "M = M + 1" << endl;
}
