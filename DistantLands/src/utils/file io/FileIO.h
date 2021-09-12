#pragma once
#include <string>
#include <fstream>
#include <stdio.h>

static void WRITE_TO_FILE(std::string file_path, std::string text)
{
    std::ofstream file;
    file.open(file_path, std::ios::app);
    file << text;
    file.close();
}
static std::string READ_FROM_FILE(std::string file_path)
{
    
    std::ifstream myfile(file_path);
    if (myfile.is_open())
    {
        std::string line;
        std::string value;
        while (getline(myfile, line))
        {
            value += line;
        }
        myfile.close();
        return value;
    }
    return std::string("");
}

static void DELETE_FILE(std::string file_path)
{
    remove(file_path.c_str());
}

static void DELETE_FILE_CONTENTS(std::string file_path)
{
    std::ofstream file;
    file.open(file_path, std::ios::trunc);
    file.close();
}