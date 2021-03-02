#include <iostream>

#include "lexer.hpp"

int main(int argc, char** argv) {
    // Get the file path of the txt in the command line argument
    std::string file_path = argv[1];

    // Start the lexical analysis of the txt content
    lexer(file_path);

    return 0;
}