#include <iostream>
#include <string>
#include <algorithm>

std::string replace_char(std::string string, char x, char y) {
    std::string new_string = string;
    std::replace(new_string.begin(), new_string.end(), x, y);

    return new_string;
}