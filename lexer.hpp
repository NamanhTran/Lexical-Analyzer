#include <iostream>
#include <algorithm>

#include "fsm.hpp"
#include "symbol_table.hpp"
#include "./utils/input_file.hpp"
#include "./utils/output.hpp"
#include "./utils/deleteComments.hpp"
#include "./utils/replace_char.hpp"
#include "./utils/addWhiteSpace.hpp"

// The lexical analyzer's logic. Takes in a string path to the txt file.
void lexer(std::string file_path) {
    // Initalize file_string, symbol tables to store tokens and lexemes, and FSM
    std::string file_string;
    std::string formatted_string;
    Symbol_Table tokens_lexemes_table;
    Lexer_FSM fsm;

    // Read the code from a txt file
    file_string = inputFile(file_path);

    // Remove all comments
    formatted_string = deleteComments(file_string);

    // Remove all newlines
    formatted_string = replace_char(formatted_string, '\n', ' ');

    // Add spaces in front and back of operators and seperators
    formatted_string = addWhiteSpace(formatted_string);

    // Loops through each character in the file
    for (int i = 0; i < formatted_string.length(); i++) {
        char curr_char = formatted_string[i];

        // If the FSM is currently at a accepted state then check if our current character is a space (end of a lexeme)
        if (fsm.is_in_accepted_state()) {
            std::string token = fsm.get_token();
            std::string lexeme = fsm.get_lexeme();

            // If current character is a space then it is a the end of an lexeme. Add to symbol table
            if (curr_char == ' ') {
                tokens_lexemes_table.add(token, lexeme);
            }

            // If the current loop is at the end of the file add the lexeme to the symbol table
            else if (i == formatted_string.length() - 1) {
                tokens_lexemes_table.add(token, lexeme);
            }
        }
        
        // Send the current chatacter into the FSM
        fsm.send_input(curr_char);
    }

    // Output all the token and lexeme pairs to a .txt file
    outputTextFile(tokens_lexemes_table.get_all_pairs());
};