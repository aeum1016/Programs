#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int main()
{
  unordered_map<string, int> digits;
  digits.emplace("**** ** ** ****", 0);
  digits.emplace("  *  *  *  *  *", 1);
  digits.emplace("***  *****  ***", 2);
  digits.emplace("***  ****  ****", 3);
  digits.emplace("* ** ****  *  *", 4);
  digits.emplace("****  ***  ****", 5);
  digits.emplace("****  **** ****", 6);
  digits.emplace("***  *  *  *  *", 7);
  digits.emplace("**** ***** ****", 8);
  digits.emplace("**** ****  ****", 9);

  string line;
  vector<string> myDigits;
  int j = 0;
  while(getline(cin, line))
  {
    for(int i = 0; i < line.size()+1/4; i+=4)
    {
      if(j == 0)
      {
        myDigits.push_back(line.substr(i, 3));
      }
      else
      {
        myDigits[i/4].append(line.substr(i, 3));
      }
    }
    j++;
  }

  int sum = 0;
  for(string s : myDigits)
  {
    sum *= 10;
    if(digits.find(s) != digits.end())
    {
      sum+=digits.at(s);
    }
    else
    {
      cout << "   BOOM!!";
      return 0;
    }
  }
  cout << (sum%6 ? "BOOM!!" : "BEER!!");
}