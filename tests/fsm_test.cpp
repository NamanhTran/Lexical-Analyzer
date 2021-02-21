#include <iostream>
#include "../fsm.hpp"
#include "../input_file.hpp"
#include "../symbol_table.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include <stdio.h>

int main() {
    Lexer_FSM fsm;
    Symbol_Table test1_table;
    std::string uncleaned_file;
    //read file and turn in to strings
    uncleaned_file = inputFile("sample_test1.txt");
    //remove all the comments 
    //clean out the comment from the file

    //hands it over to fsm
    for(int i = 0; i < uncleaned_file.size() - 1; i++) {
        if(uncleaned_file[i] == ' ' && fsm.is_in_accepted_state()) {
            test1_table.add(fsm.get_token(), fsm.get_lexeme());
        }
        fsm.send_input(uncleaned_file[i]);
    }
    test1_table.add(fsm.get_token(), fsm.get_lexeme());
    
    auto vector_pairs = test1_table.get_all_pairs();
    std::cout << "TOKEN     Lexemes\n";
    for(auto it = vector_pairs.begin(); it != vector_pairs.end(); it++) {
        std::cout << it->first << " " << it->second << "\n";
    }

    // the key is the token and value is the lexeme
    return 0;
}