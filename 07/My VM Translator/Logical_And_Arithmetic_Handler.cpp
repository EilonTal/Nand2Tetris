//
// Created by Roe on 8/22/2020.
//

#include "Logical_And_Arithmetic_Handler.h"

Logical_And_Arithmetic_Handler::Logical_And_Arithmetic_Handler(ofstream & output_file,
                                                               vector<string> tokens, int & label_index):
label_index(label_index), output_file(output_file)
{
    string first_word = tokens[0];
    if (first_word == "add")
        handleAdd();
    else if (first_word == "sub")
        handleSub();
    else if (first_word == "neg")
        handleNeg();
    else if (first_word == "eq")
        handleEq();
    else if (first_word == "gt")
        handleGt();
    else if (first_word == "lt")
        handleLt();
    else if (first_word == "and")
        handleAnd();
    else if (first_word == "or")
        handleOr();
    else if (first_word == "not")
        handleNot();
}

void Logical_And_Arithmetic_Handler::handleAdd()
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D + M" << endl;
}

void Logical_And_Arithmetic_Handler::handleSub()
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D - M" << endl;
    output_file << "M = -M" << endl;
}

void Logical_And_Arithmetic_Handler::handleNeg()
{
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -M" << endl;
}

void Logical_And_Arithmetic_Handler::handleEq()
{
    int label1 = get_new_label_index();
    int label2 = get_new_label_index();
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M-D" << endl;
    output_file << "@Label" << label1 << endl;
    output_file << "D;JEQ" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = 0" << endl;
    output_file << "@Label" << label2 << endl; // if its == 0 then jump to end
    output_file << "0;JMP" << endl;
    output_file << "(Label" << label1 << ")" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -1" << endl;
    output_file << "(Label" << label2 << ")" << endl; // end
}

void Logical_And_Arithmetic_Handler::handleGt()
{
    int label1 = get_new_label_index();
    int label2 = get_new_label_index();
    output_file << "@SP" << endl;
    output_file << "AMD = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M-D" << endl;
    output_file << "@Label" << label1 << endl;
    output_file << "D;JGT" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = 0" << endl;
    output_file << "@Label" << label2 << endl; // if its == 0 then jump to end
    output_file << "0;JMP" << endl;
    output_file << "(Label" << label1 << ")" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -1" << endl;
    output_file << "(Label" << label2 << ")" << endl; // end
}

void Logical_And_Arithmetic_Handler::handleLt()
{
    int label1 = get_new_label_index();
    int label2 = get_new_label_index();
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "D = M-D" << endl;
    output_file << "@Label" << label1 << endl;
    output_file << "D;JLT" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = 0" << endl;
    output_file << "@Label" << label2 << endl; // if its == 0 then jump to end
    output_file << "0;JMP" << endl;
    output_file << "(Label" << label1 << ")" << endl;
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = -1" << endl;
    output_file << "(Label" << label2 << ")" << endl; // end
}

void Logical_And_Arithmetic_Handler::handleAnd()
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D&M" << endl;
}

void Logical_And_Arithmetic_Handler::handleOr()
{
    output_file << "@SP" << endl;
    output_file << "AM = M - 1" << endl;
    output_file << "D = M" << endl;
    output_file << "A = A - 1" << endl;
    output_file << "M = D|M" << endl;
}

void Logical_And_Arithmetic_Handler::handleNot()
{
    output_file << "@SP" << endl;
    output_file << "A = M - 1" << endl;
    output_file << "M = !M" << endl;
}

int Logical_And_Arithmetic_Handler::get_new_label_index()
{
    label_index ++;
    return label_index - 1;
}
