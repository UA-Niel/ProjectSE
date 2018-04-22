
#ifndef UTILS_H
#define UTILS_H


#include <iostream>

bool DirectoryExists(const std::string dirname);

bool FileExists(const std::string dirname);

bool FileIsEmpty(const std::string filename);

bool FileCompare(const std::string leftFileName, const std::string rightFileName);

std::string ToString(int i);

template<typename T>
T fromStr(std::string str) {
    std::istringstream ss(str);
    T ret;
    ss >> ret;
    return ret;
}

// Closing of the ``header guard''.
#endif
