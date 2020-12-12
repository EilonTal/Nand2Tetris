#include "Command_Handler.h"
#include <filesystem>
#include <string>


void handleLinesFromFile(string path_to_file, ofstream & output_file);


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



void handleLinesFromDir(string path_to_dir, ofstream & output_file)
{
    string path_to_file;
    for (const auto & entry : std::filesystem::directory_iterator(path_to_dir))
    {
        path_to_file = entry.path().string();
        if (path_to_file.find(".vm") != string::npos)
            handleLinesFromFile(path_to_file, output_file);
    }
}

void handleLinesFromFile(string path_to_file, ofstream & output_file)
{

    ifstream input_file (path_to_file);
    string full_file_name_without_suffix = path_to_file.substr(0, path_to_file.find(".vm"));
    string file_name_without_suffix = full_file_name_without_suffix.substr
            (full_file_name_without_suffix.find_last_of('\\') + 1);
    Command_Handler commandHandler(output_file, file_name_without_suffix);
    string line;
    for (int i = 0; getline(input_file, line); i++)
    {
        commandHandler.advance(line);
    }
}

void init (string path_to_file, ofstream & output_file)
{
    string full_file_name_without_suffix = path_to_file.substr(0, path_to_file.find(".vm"));
    string file_name_without_suffix = full_file_name_without_suffix.substr
            (full_file_name_without_suffix.find_last_of('\\') + 1);
    Command_Handler commandHandler(output_file, file_name_without_suffix);
    output_file << "@256" << endl;
    output_file << "D = A" << endl;
    output_file << "@SP" << endl;
    output_file << "M = D" << endl;
    string line = "call Sys.init 0";
    commandHandler.advance(line);
}

int main(int argc, char ** argv)
{
    string input_path_str = argv[1];
    ofstream output_file (getNameOfOutputFile(input_path_str));
    init(input_path_str, output_file);
    Command_Handler::init_label_index();
    if (std::filesystem::is_directory(input_path_str))
        handleLinesFromDir(input_path_str, output_file);
    else
        handleLinesFromFile(input_path_str, output_file);
    output_file.close();
    return 0;
}
