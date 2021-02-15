#include <iostream>
#include "../symbol_table.hpp"
int main() {
    Symbol_Table test_obj;

    test_obj.add("keyword", "int");
    test_obj.add("keyword", "char");
    test_obj.add("demlimiter", ";");

    std::vector<std::pair<std::string, std::string>> test_vector = test_obj.get_all_pairs();
    
    for (int i = 0; i < test_vector.size(); i++) {
        std::cout << test_vector[i].first << " " << test_vector[i].second <<"\n";
    }

    return 0;
}