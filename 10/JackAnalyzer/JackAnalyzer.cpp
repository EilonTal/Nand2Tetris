//
// Created by eilon on 06/01/2021.
//

#include <filesystem>
#include <iostream>
#include <string>
#include "CompilationEngine.h"
using namespace std;

void handleLinesFromFile(string path_to_file);


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
        return file + last_backslash + last_dir_name + ".xml";
    }
    string file_name_without_suffix = file.substr(0, file.find(".jack"));
    return file_name_without_suffix + ".xml";
}


void handleLinesFromDir(string path_to_dir)
{
    string path_to_file;
    for (const auto & entry : std::filesystem::directory_iterator(path_to_dir))
    {
        path_to_file = entry.path().string();
        if (path_to_file.find(".jack") != string::npos)
            handleLinesFromFile(path_to_file);
    }
}

void handleLinesFromFile(string path_to_file)
{
    ifstream input_file (path_to_file);
  //  ofstream output_file (getNameOfOutputFile(path_to_file));
    CompilationEngine compiler(input_file, std::cout);
    input_file.close();
    //output_file.close();
}

int main(int argc, char ** argv)
{
    string input_path_str = "C:\\Users\\Roe\\Documents\\GitHub\\Nand2Tetris\\10\\ArrayTest\\Main.jack";
    if (std::filesystem::is_directory(input_path_str))
        handleLinesFromDir(input_path_str);
    else
        handleLinesFromFile(input_path_str);
    return 0;
}
