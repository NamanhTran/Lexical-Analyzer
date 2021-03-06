#include<iostream>

// This is to check if the current character is a separator or an operator
bool isSeparatorOrOperator(char ch)
{
  if (ch == '(' || ch == '{' || ch == '[' || ch == ')' || ch == '}' ||
      ch == ']' || ch == ',' || ch == '.' || ch == ':' || ch == ';' ||
      ch == '*' || ch == '=' || ch == '-' || ch == '=' || ch == '/' ||
      ch == '>' || ch == '<' || ch == '%')
    return true;
  else
    return false;
}

std::string addWhiteSpace(std::string c)
{
  std::string temp1;
  std::string temp2;
  bool needSpace;

  // This for loop will iterate through the string and insert white spaces
  // before and after an operator and a separator
  for(int i = 0; i < c.length(); i++)
  {
    // isSeparatorOrOperator will return true if the current character is
    // an operator or a separator
    needSpace = isSeparatorOrOperator(c[i]);

    //This if statement is for float numbers, if a period is being used for
    //a float number, we should not add spaces in between the period
    if(isdigit(c[i-1]) && c[i] == '.')
    {
      continue;
    }
    else if (isdigit(c[i+1]) && c[i] == '.')
    {
      continue;
    }
    
    // If the current character we are at is an operator or a separator, we will
    // add a space before and after the operator or separator
    if (needSpace == true)
    {
      temp1 = c.substr(0,i);
      temp2 = c.substr(i+1, c.length());
      c = temp1 + " " + c[i] + " " + temp2;
      i++;
    }
  }
  return c;
}
