//
// Created by Roe on 8/22/2020.
//

#include "Logical_And_Arithmetic_Handler.h"

Logical_And_Arithmetic_Handler::Logical_And_Arithmetic_Handler(
        string current_command, ofstream &output_file, vector<string> tokens, int & label_index):
        label_index(label_index)
{
    string first_word = tokens[0];
    if (first_word == "add")
        handleAdd(output_file);
    else if (first_word == "sub")
        handleSub(output_file);
    else if (first_word == "neg")
        handleNeg(output_file);
    else if (first_word == "eq")
        handleEq(output_file);
    else if (first_word == "gt")
        handleGt(output_file);
    else if (first_word == "lt")
        handleLt(output_file);
    else if (first_word == "and")
        handleAnd(output_file);
    else if (first_word == "or")
        handleOr(output_file);
    else if (first_word == "not")
        handleNot(output_file);
}

void Logical_And_Arithmetic_Handler::handleAdd(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "M = M - 1" << endl;
    output_file << "A = M" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D + M" << endl;
}

void Logical_And_Arithmetic_Handler::handleSub(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "M = M - 1" << endl;
    output_file << "A = M" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D - M" << endl;
    output_file << "M = -M" << endl;
}

void Logical_And_Arithmetic_Handler::handleNeg(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -M" << endl;
}

void Logical_And_Arithmetic_Handler::handleEq(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M-D" << endl;
    output_file << "@Label" << label_index << endl;
    output_file << "D;JEQ" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = 0" << endl;
    output_file << "@Label" << label_index + 1 << endl; // if its == 0 then jump to end
    output_file << "0;JMP" << endl;
    output_file << "(Label" << label_index << ")" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -1" << endl;
    output_file << "(Label" << label_index + 1 << ")" << endl; // end
    label_index += 2;
}

void Logical_And_Arithmetic_Handler::handleGt(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M-D" << endl;
    output_file << "@Label" << label_index << endl;
    output_file << "D;JGT" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = 0" << endl;
    output_file << "@Label" << label_index + 1 << endl; // if its == 0 then jump to end
    output_file << "0;JMP" << endl;
    output_file << "(Label" << label_index << ")" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -1" << endl;
    output_file << "(Label" << label_index + 1 << ")" << endl; // end
    label_index += 2;
}

void Logical_And_Arithmetic_Handler::handleLt(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M-D" << endl;
    output_file << "@Label" << label_index << endl;
    output_file << "D;JLT" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = 0" << endl;
    output_file << "@Label" << label_index + 1 << endl; // if its == 0 then jump to end
    output_file << "0;JMP" << endl;
    output_file << "(Label" << label_index << ")" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -1" << endl;
    output_file << "(Label" << label_index + 1 << ")" << endl; // end
    label_index += 2;
}

void Logical_And_Arithmetic_Handler::handleAnd(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D&M" << endl;
}

void Logical_And_Arithmetic_Handler::handleOr(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D|M" << endl;
}

void Logical_And_Arithmetic_Handler::handleNot(ofstream &output_file)
{
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = !M" << endl;
}
