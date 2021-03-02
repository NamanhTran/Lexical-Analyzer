#include <iostream>
#include <string>
#include <algorithm>

std::string replace_new_lines(std::string string, char c) {
    std::string new_string = string;
    std::replace(new_string.begin(), new_string.end(), '\n', c);

    return new_string;
}