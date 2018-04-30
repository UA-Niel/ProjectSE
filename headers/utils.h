/**
 * \file This file contains the declaration of some util functions
 */

#ifndef UTILS_H
#define UTILS_H


#include <iostream>

/**
 * \brief Checks if a directory exists
 * @param dirname String specifying the path to the directory
 * @return True if the directory exists
 */
bool DirectoryExists(const std::string dirname);

/**
 * \brief Checks if a file exists
 * @param dirname String specifying the path to the file
 * @return True if the file exists
 */
bool FileExists(const std::string dirname);

/**
 * \brief Checks if a file is empty
 * @param filename Path to the file
 * @return True if the file is empty
 */
bool FileIsEmpty(const std::string filename);

/**
 * \brief Compares to files
 * @param leftFileName First file to compare
 * @param rightFileName Second file to compare
 * @return True if the files are the same
 */
bool FileCompare(const std::string leftFileName, const std::string rightFileName);

/**
 * \brief Converts an integer to a String
 * @param i Input integer
 * @return String value of the integer
 */
std::string ToString(int i);

template<typename T>
/**
 * \brief Returns an object based on the string value of the objects name
 * @tparam T Type of the object to return
 * @param str String containing the name of the type of the object
 * @return Object
 */
T fromStr(std::string str) {
    std::istringstream ss(str);
    T ret;
    ss >> ret;
    return ret;
}

// Closing of the ``header guard''.
#endif
