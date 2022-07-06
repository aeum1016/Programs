#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  vector<string> keyboard;
  string nums="1234567890-=";
  string topRowCaps="QWERTYUIOP[]\\";
  string midRowCaps="ASDFGHJKL;'";
  string botRowCaps="ZXCVBNM,./";

  keyboard.push_back(nums);
  keyboard.push_back(topRowCaps);
  keyboard.push_back(midRowCaps);
  keyboard.push_back(botRowCaps);

  string line;
  while(getline(cin, line))
  {
    string newLine = "";
    for(char c : line)
    {
      if(c != ' ')
      {
        for(int i = 0; i < keyboard.size(); i++)
        {
          if(keyboard.at(i).find(c) != string::npos)
          {
            newLine.append(keyboard.at(i).substr(keyboard.at(i).find(c)-1, 1));
          }
        }
      }
      else newLine.append(" ");
    }
    cout << newLine << endl;
  }
}