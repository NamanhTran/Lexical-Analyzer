#include <iostream>
#include <string>

#include "lexer.hpp"

int main(int argc, char** argv) {
    // If the path file was not provided then print the usage instruction
    if (argc != 2) {
        std::cout << "Error no path to test case text file provided in command line." << std::endl;
        std::cout << "Usage: ./main [file_path_to_txt]" << std::endl;

        return 1;
    }

    // Get the file path of the txt in the command line argument
    std::string file_path = argv[1];

    // Start the lexical analysis of the txt content
    lexer(file_path);

    return 0;
}