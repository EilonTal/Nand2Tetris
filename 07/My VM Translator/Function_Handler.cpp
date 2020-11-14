//
// Created by Roe on 8/22/2020.
//

#include "Function_Handler.h"
Function_Handler::Function_Handler(string current_command, ofstream& output_file,
                                   vector<string>& tokens, int & label_index):
current_command(current_command), output_file(output_file), tokens(tokens), label_index(label_index)
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

    //
    output_file << "@SP" << endl;
    output_file << "@SP" << endl;
    output_file << "@SP" << endl;
    output_file << "@SP" << endl;
    output_file << "@SP" << endl;

    label_index += 1; // make sure
}

void Function_Handler::handle_function()
{

}

void Function_Handler::handle_return()
{

}
