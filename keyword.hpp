#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isKeyword(string str) {
    if(str == "int" || str == "float" || str == "bool" || str == "True" || str == "False" || str == "if" || str == "else" || str == "then" || str == "endif" || str == "endelse" || str == "while" || str == "whileend" || str == "do" || str == "enddo" || str == "for" || str == "endfor" || str == "STDinput" || str == "STDoutput" || str == "and" || str == "or" || str == "not") 
        return true;
    else
        return false;
 }