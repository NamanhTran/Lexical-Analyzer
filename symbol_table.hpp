#include <vector>
#include <utility>
#include <string>

// symbol table  keeps track of the tokens and lemexes
class Symbol_Table {
    public:
        void add(std::string key, std::string value);
        std::vector<std::pair<std::string, std::string>> get_all_pairs();

    private:
        std::vector<std::pair<std::string, std::string>> pair_vector;
};

// adds key and value pair to the vector
void Symbol_Table::add(std::string key, std::string value) {
    pair_vector.push_back(std::make_pair(key, value));
}

// returns the vector that contains string, string pairs
std::vector<std::pair<std::string, std::string>> Symbol_Table::get_all_pairs(){
    return this->pair_vector;
}