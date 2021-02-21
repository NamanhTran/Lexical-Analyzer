#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isOperator(char c) {
    if (c == '*' || c == '+' || c == '-' || c == '=' || c == '/' || c == '>' || c == '<' || c == '%') {
        // cout<<"OPERATOR =      "<<c<<"\n";
        return true;
    }
     return false;
 }