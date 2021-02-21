#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isSeparator(char c) {
    if (c == '\'' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == '.' || c == ':' || c == ';') {
        // cout<<"SEPARATOR =      "<<c<<"\n";
        return true;
    }
     return false;
 }