#include<iostream>
#include<fstream>
using namespace std;

string deleteComments(string c)
{
  int n = c.length();
  bool comment = false;
  string newString;

  //Traverse the string
  for(int i = 0; i < n; ++i)
  {
      // This happens if we are at the end of a comment
      if (comment == true && c[i] == '\n')
      {
        comment = false;
      }
      //This is where skipping the entire line happens
      else if (comment == true)
      {
        continue;
      }
      //If it starts with a comment, then comment turns true and we incremement
      else if (c[i] == '!')
      {
        comment = true;
        i++;
      }
      //Else we add each letter to the new string
      else
      {
        newString += c[i];
      }
  }
  return newString;
}