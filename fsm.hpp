#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include <stdio.h>


class Lexer_FSM {
    public:
        Lexer_FSM();

        // Sends an input to FSM to change the state
        void send_input(char c);
        
        // Checks if the FSM is in a accepted state
        bool is_in_accepted_state();

        // Returns the token
        std::string get_token();

        // Returns the lexeme
        std::string get_lexeme();

    private:
        // Keeps track of lexeme that is currently being parsed
        std::string lexeme;

        // Keep track on which state the FSM is in
        std::string state;

        // A flag to check if the lexeme has a decial already
        int has_decimal;

        // Create sets of keywords, operators, and seperators
        std::set<std::string> keywords_set;
        std::set<std::string> operators_set;
        std::set<std::string> seperators_set;

        // Loads all lexemes into the set
        void insert_strings_from_file_into_set(std::string file_path, std::set<std::string>* set);
        
        // Gets the input type for the transition table
        std::string get_char_type(char character);

        // FSM's state transition table
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> state_transition_table;
};

Lexer_FSM::Lexer_FSM() {
    // Initialize the lexeme string and the starting state of the FSM
    std::string lexeme = "";
    this->state = "Starting";

    // Load all of the strings from the token files into the appropriate set.
    this->insert_strings_from_file_into_set("../tokens/keywordsLexemes.txt", &keywords_set);
    this->insert_strings_from_file_into_set("../tokens/operatorsLexemes.txt", &operators_set);
    this->insert_strings_from_file_into_set("../tokens/seperatorsLexemes.txt", &seperators_set);

    // The state transition table declaration
    this->state_transition_table = {
        {"Starting", 
            {
                {"Alphabetical", "Identifier"},
                {"Seperator", "Seperator"},
                {"Operator", "Operator"},
                {"Numerical", "Real"},
                {"_", "Error"},
                {"$", "Error"},
                {"Space", "Starting"},
                {".", "Seperator"},
                {"Everything Else", "Error"}
            }
        },
        
        {"Identifier",
            {
                {"Alphabetical", "Identifier"},
                {"Seperator", "Error"},
                {"Operator", "Error"},
                {"Numerical", "Identifier"},
                {"_", "Identifier"},
                {"$", "Identifier"},
                {"Space", "Starting"},
                {".", "Error"},
                {"Everything Else", "Error"}
            }
        },

        {"Seperator",
            {
                {"Alphabetical", "Error"},
                {"Seperator", "Error"},
                {"Operator", "Error"},
                {"Numerical", "Error"},
                {"_", "Error"},
                {"$", "Error"},
                {"Space", "Starting"},
                {".", "Error"},
                {"Everything Else", "Error"}
            }
        },

        {"Operator",
            {
                {"Alphabetical", "Error"},
                {"Seperator", "Error"},
                {"Operator", "Error"},
                {"Numerical", "Error"},
                {"_", "Error"},
                {"$", "Error"},
                {"Space", "Starting"},
                {".", "Error"},
                {"Everything Else", "Error"}
            }
        },

        {"Error",
            {
                {"Alphabetical", "Error"},
                {"Seperator", "Error"},
                {"Operator", "Error"},
                {"Numerical", "Error"},
                {"_", "Error"},
                {"$", "Error"},
                {"Space", "Starting"},
                {".", "Error"},
                {"Everything Else", "Error"}
            }
        },

        {"Real",
            {
                {"Alphabetical", "Error"},
                {"Seperator", "Error"},
                {"Operator", "Error"},
                {"Numerical", "Real"},
                {"_", "Error"},
                {"$", "Error"},
                {"Space", "Starting"},
                {".", "Error"},
                {"Everything Else", "Error"}
            }
        }
    };
}

// Sends an input to FSM to change the stat
void Lexer_FSM::send_input(char character) {
    // Get the input type of the character provided
    std::string inputType = get_char_type(character);

    // Get the next state of the FSM 
    if (this->state == "Real" && inputType == "." && !this->has_decimal) {
        this->has_decimal = true;
        this->state = "Real";
    }

    // If state is at a seperator (the seperator is a '.'), and the input type is numerical then move it to the real number state
    else if (this->state == "Seperator" && inputType == "Numerical" && this->lexeme[0] == '.') {
        this->state = "Real";
    }

    // Get the state from the state table
    else {
        this->state = this->state_transition_table[this->state][inputType];
    }

    // If the character is a space that means it is a new lexeme so we do not want to add it to the lexeme string
    if (character != ' ') { 
        this->lexeme += character;
    }

    // If a space is the input type then reset the FSM and prepare for the next lexeme
    else {
        this->has_decimal = false;
        this->lexeme = "";
        this->state = "Starting";

    }
}

// Gets the input type for the transition table
std::string Lexer_FSM::get_char_type(char character) {
    // Set a string class for the character so we can use the string to search through the sets
    std::string characterString(1, character);

    if (character == '.') {
        return ".";
    }

    // Checks if the character passed is alphabetical
    else if (isalpha(character)) {
        return "Alphabetical";
    }

    // Checks if the character passed is a numeric
    else if (isdigit(character)) {
        return "Numerical";
    }

    // Checks if the character passed is an operator
    else if (this->operators_set.find(characterString) != this->operators_set.end()) {
        return "Operator";
    }

    // Checks if the character passed is a seperator
    else if (this->seperators_set.find(characterString) != this->seperators_set.end()) {
        return "Seperator";
    }

    // Check if the character is an underscore
    else if (character == '_') {
        return "_";
    }

    // Checks if the character is an dollar sign
    else if (character == '$') {
        return "$";
    }

    // Checks if the character is a space
    else if (character == ' ') {
        this->lexeme = "";
        return "Space";
    }

    // Checks if the character is not a valid input type
    else {
        return "Everything Else";
    }
}

// Loads all lexemes into the set
void Lexer_FSM::insert_strings_from_file_into_set(std::string filePath, std::set<std::string>* set) {
    std::string fileString;
    std::ifstream my_file(filePath);

    // Checks if the file is opened correctly
    if (my_file.is_open()) {
        // Add the string to the set
        while (my_file >> fileString) {
            set->insert(fileString);
        }
    } 
    
    // Print out the file that failed to open
    else {
        std::cout << filePath << " did not open" << std::endl;
    }

    my_file.close();
}

// Returns the token
std::string Lexer_FSM::get_token() {
    if(this->keywords_set.find(lexeme) != this->keywords_set.end()) {
        return "Keyword";
    }

    return this->state;
}

// Returns the lexeme
std::string Lexer_FSM::get_lexeme() {
    return this->lexeme;
}

// Checks if the FSM is in an accepted state
bool Lexer_FSM::is_in_accepted_state() {
    if (this->state == "Starting" || this->state == "Error") {
        return false;
    }

    return true;
}