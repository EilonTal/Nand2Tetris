#include "Command_Handler.h"
#include <filesystem>
#include <string>
#include <iostream>


void getLinesFromFile(string path_to_file, vector<string>& lines);



inline bool doesPathEndWithBackslash(string file)
{
    return file.find_last_of('\\') == file.size()-1;
}

string getLastDirName(string file)
{
    if (doesPathEndWithBackslash(file))
        file = file.substr(0, file.size()-1);
    int index_last_backslash = file.find_last_of('\\');
    return file.substr(index_last_backslash + 1, file.size() - index_last_backslash - 1);
}

string getNameOfOutputFile(string file)
{
    std::filesystem::path path = file;
    if (std::filesystem::is_directory(path))
    {
        string last_dir_name = getLastDirName(file);
        string last_backslash = (doesPathEndWithBackslash(file))? "" : "\\";
        return file + last_backslash + last_dir_name + ".asm";
    }
    string file_name_without_suffix = file.substr(0, file.find(".vm"));
    return file_name_without_suffix + ".asm";
}



void getLinesFromDirectory(string path_to_dir, vector<string>& lines)
{
    string path_to_file;
    for (const auto & entry : std::filesystem::directory_iterator(path_to_dir))
    {
        path_to_file = entry.path().string();
        if (path_to_file.find(".vm") != string::npos)
            getLinesFromFile(path_to_file, lines);
    }
}

void getLinesFromFile(string path_to_file, vector<string>& lines)
{
    ifstream input(path_to_file);
    string line;
    for (int i = 0; getline(input, line); i++)
        lines.push_back(line);
    input.close();
}

int main(int argc, char ** argv)
{
    vector<string> lines;
    string input_path_str = argv[1];
    std::filesystem::path path = input_path_str;
    if (std::filesystem::is_directory(input_path_str))
        getLinesFromDirectory(input_path_str, lines);
    else
        getLinesFromFile(input_path_str ,lines);
    ofstream output_file(getNameOfOutputFile(input_path_str));
    string full_file_name_without_suffix = input_path_str.substr(0, input_path_str.find(".vm"));
    string file_name_without_suffix = full_file_name_without_suffix.substr
            (full_file_name_without_suffix.find_last_of('\\') + 1);
    Command_Handler commandHandler(output_file, lines, file_name_without_suffix);
    while (commandHandler.isThereAnotherCommand())
    {
        commandHandler.advance();
    }
    return 0;
}
