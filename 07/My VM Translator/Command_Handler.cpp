//
// Created by Roe on 8/22/2020.
//
//s
#include "Command_Handler.h"
Command_Handler::Command_Handler(ofstream & output_file, vector<string>& lines, string file_name_without_suffix):
 current_command(), output_file(output_file), lines(lines),
 current_command_index(0), file_name_without_suffix(file_name_without_suffix), label_index(0)
{
    int index_start = file_name_without_suffix.find_last_of('\\');
    int size = file_name_without_suffix.size();
    file_name_without_suffix = file_name_without_suffix.substr(index_start + 1, size - index_start);
}

bool Command_Handler::isThereAnotherCommand()
{
    if(current_command_index == lines.size())
        return false;
    return true;
}

bool Command_Handler::isCommandArithmeticOrLogic(string first_word)
{
    if (first_word == "add" || first_word == "sub" || first_word == "neg" || first_word == "eq" ||
        first_word == "gt" || first_word == "lt" || first_word == "and" || first_word == "or" || first_word == "not")
        return true;
    return false;
}

bool Command_Handler::isCommandMemoryAccess(string first_word)
{
    if (first_word == "push" || first_word == "pop")
        return true;
    return false;
}

bool Command_Handler::isCommandBranch(string first_word)
{
    if (first_word == "label" || first_word == "goto" || first_word == "if-goto")
        return true;
    return false;
}

bool Command_Handler::isCommandFunction(string first_word)
{
    if (first_word == "function" || first_word == "call" || first_word == "return")
        return true;
    return false;
}

void Command_Handler::advance()
{
    current_command = lines[current_command_index];
    if (!current_command.empty())
    {
        vector<string> tokens = split(current_command, ' ');
        string first_word = tokens[0];
        if (!first_word.empty() && !isTokenAnnotation(first_word)) // doesnt start with "//"
        {
            for (string token: tokens)
            {
                token = getTokenWithoutAnnotation(token);
            }
            if (isCommandArithmeticOrLogic(first_word)) {
                Logical_And_Arithmetic_Handler obj(current_command, output_file, tokens, label_index);
                current_command_index++;
            }
            else if (isCommandBranch(first_word)) {
                Branching_Handler obj(current_command, output_file, tokens);
                if (obj.didJump())
                    current_command_index = obj.getNewCommandIndex();
            }
            else if (isCommandFunction(first_word)) {
                Function_Handler obj(current_command, output_file, tokens);
                current_command_index++;
            }
            else if (isCommandMemoryAccess(first_word)) {
                Memory_Access_Handler obj(current_command,
                                          output_file, file_name_without_suffix, tokens);
                current_command_index++;
            }
        }
        else
            current_command_index++;
    }
    else
        current_command_index++;
}

Command_Handler::~Command_Handler()
{
    output_file.close();
}

