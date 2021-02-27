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
#include<iomanip>

void outputTextFile(vector <pair<string, string>> x);

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
    
    outputTextFile(test1_table.get_all_pairs());

    // the key is the token and value is the lexeme
    return 0;
}

void outputTextFile(vector <pair<string, string>> x)
{
  std::ofstream outputFile;
  outputFile.open("output.txt");
  outputFile << "       Output:       " << endl;
  outputFile << "Token          Lexeme" << endl;
  outputFile << "---------------------" << endl;
  for (int i = 0; i < x.size(); ++i)
  {
    outputFile << x[i].first << std::right << setw(21 - x[i].first.length()) << x[i].second << std::endl;
  }
  outputFile.close();
}