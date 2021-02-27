#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

void outputTextFile(std::vector <std::pair<std::string, std::string>> x)
{
  std::ofstream outputFile;
  outputFile.open("output.txt");
  for (int i = 0; i < x.size(); ++i)
  {
    outputFile << x[i].first << std::right << std::setw(21-x[i].first.length()) << x[i].second << std::endl;
  }
  outputFile.close();
}
