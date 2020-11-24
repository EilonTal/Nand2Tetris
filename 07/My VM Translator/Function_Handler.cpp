//
// Created by Roe on 8/22/2020.
//

#include "Function_Handler.h"
Function_Handler::Function_Handler(ofstream& output_file, vector<string>& tokens, int & label_index):
output_file(output_file), tokens(tokens), label_index(label_index)
{
    string first_word = tokens[0];
    if (first_word == "call")
        handle_call();
    else if (first_word == "function")
        handle_function();
    else if (first_word == "return")
        handle_return();
}

void Function_Handler::handle_call()
{
    string function_name = tokens[1];
    string num_vars_str = tokens[2];

    // region save return address
    output_file << "@Label" << label_index << endl;
    output_file << "D = A" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;
    output_file << "@SP" << endl;
    output_file << "M = M + 1" << endl;
    // endregion

    // region save LCL
    output_file << "@LCL" << endl;
    output_file << "D = M" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;
    output_file << "@SP" << endl;
    output_file << "M = M + 1" << endl;

    // endregion

    // region save ARG
    output_file << "@ARG" << endl;
    output_file << "D = M" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;
    output_file << "@SP" << endl;
    output_file << "M = M + 1" << endl;

    // endregion

    // region save THIS
    output_file << "@THIS" << endl;
    output_file << "D = M" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;
    output_file << "@SP" << endl;
    output_file << "M = M + 1" << endl;
    // endregion

    // region save THAT
    output_file << "@THAT" << endl;
    output_file << "D = M" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;
    output_file << "@SP" << endl;
    output_file << "M = M + 1" << endl;
    // endregion

    // region push new ARG
    output_file << "@5" << endl;
    output_file << "D = A" << endl;
    output_file << "@SP" << endl;
    output_file << "D = M - D" << endl;
    output_file << "@tempVar" << endl;
    output_file << "M = D" << endl;
    output_file << "@" << num_vars_str << endl;
    output_file << "D = A" << endl;
    output_file << "@tempVar" << endl;
    output_file << "D = D - M" << endl;
    output_file << "@ARG" << endl;
    output_file << "M = D" << endl;
    //endregion

    // region push new LCL

    output_file << "@SP" << endl;
    output_file << "D = M" << endl;
    output_file << "@LCL" << endl;
    output_file << "M = D" << endl;

    // endregion

    //region goto function

    output_file << "@" << function_name << endl;
    output_file << "0;JMP" << endl;

    //endregion

    //region insert return address

    output_file << "(Label" << label_index << ")" << endl;

    //endregion

    label_index ++;
}

void Function_Handler::handle_function()
{
    string function_name = tokens[1];
    string num_vars_str = tokens[2];

    // region insert function name

    output_file << "(" << function_name << ")" << endl;

    //endregion

    //region push zeros as locals
    int num_vars = stoi(num_vars_str);
    for (int i = 0; i < num_vars; i++)
    {
        output_file << "@SP" << endl;
        output_file << "A = M" << endl;
        output_file << "M = 0" << endl;
        output_file << "@SP" << endl;
        output_file << "M = M + 1" << endl;
    }
    //endregion
}

void Function_Handler::handle_return()
{

    //region init end frame var

    output_file << "@LCL" << endl;
    output_file << "D = A" << endl;
    output_file << "@endFrame" << endl;
    output_file << "M = D" << endl;

    //endregion

    //region init return address var

    output_file << "@5" << endl;
    output_file << "D = A" << endl;
    output_file << "@endFrame" << endl;
    output_file << "D = A - D" << endl;
    output_file << "A = D" << endl;
    output_file << "D = M" << endl;
    output_file << "@retAddress" << endl;
    output_file << "M = D" << endl;

    //endregion

    //region give return value to caller

    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "@ARG" << endl;
    output_file << "A = M" << endl;
    output_file << "M = D" << endl;

    //endregion

    //region reposition SP

    output_file << "@ARG" << endl;
    output_file << "D = A + 1" << endl;
    output_file << "@SP" << endl;
    output_file << "M = D" << endl;

    //endregion

    //region recover THAT

    output_file << "@endFrame" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "@THAT" << endl;
    output_file << "M = D" << endl;


    //endregion

    //region recover THIS

    output_file << "@endFrame" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "@THIS" << endl;
    output_file << "M = D" << endl;

    //endregion

    //region recover ARG

    output_file << "@endFrame" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "@ARG" << endl;
    output_file << "M = D" << endl;


    //endregion

    //region recover LCL

    output_file << "@4" << endl;
    output_file << "D = A" << endl;
    output_file << "@endFrame" << endl;
    output_file << "A = M - D" << endl;
    output_file << "D = M" << endl;
    output_file << "@ARG" << endl;
    output_file << "M = D" << endl;

    //endregion

    //region goto return address

    output_file << "@retAddress" << endl;
    output_file << "0;JMP" << endl;

    //endregion
}