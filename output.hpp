#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

void outputTextFile(vector <pair<string, string>> x)
{
  ofstream outputFile;
  outputFile.open("output.txt");
  outputFile << "       Output:       " << endl;
  outputFile << "Token          Lexeme" << endl;
  outputFile << "---------------------" << endl;
  for (int i = 0; i < x.size(); ++i)
  {
    outputFile << x[i].first << setw(12) << x[i].second << endl;
  }
  outputFile.close();
}
