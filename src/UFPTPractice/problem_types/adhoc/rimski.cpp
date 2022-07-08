#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
  unordered_map<string, int> ones;
  unordered_map<string, int> tens;

  ones.emplace("I", 1);
  ones.emplace("II", 2);
  ones.emplace("III", 3);
  ones.emplace("IV", 4);
  ones.emplace("V", 5);
  ones.emplace("VI", 6);
  ones.emplace("VII", 7);
  ones.emplace("VIII", 8);
  ones.emplace("IX", 9);

  tens.emplace("", 0);
  tens.emplace("X", 10);
  tens.emplace("XX", 20);
  tens.emplace("XXX", 30);
  tens.emplace("XL", 40);
  tens.emplace("L", 50);
  tens.emplace("LX", 60);
  tens.emplace("LXX", 70);
  tens.emplace("LXXX", 80);
  tens.emplace("XC", 90);

  string num; cin >> num;

  int value = 100;

  string fullValue = "";
  string afterTens = "";

  for(auto it = tens.begin(); it != tens.end(); it++)
  {
    string temp(num);
    for(char c : it->first)
    {
      if(temp.find(c) != string::npos)
      {
        temp = temp.substr(0,temp.find(c)) + temp.substr(temp.find(c)+1);
      }
      else{
        break;
      }
    }
    if(temp.size() == num.size()-it->first.size())
    {
      afterTens = temp;
      for(auto it2 = ones.begin(); it2 != ones.end(); it2++)
      {
        temp = afterTens;
        for(char c : it2->first)
        {
          if(temp.find(c) != string::npos)
          {
            temp = temp.substr(0,temp.find(c)) + temp.substr(temp.find(c)+1);
          }
          else{
            break;
          }
        }
        if(temp.size() == 0)
        {
          if(it2->second + it->second < value)
          {
            value = it2->second + it->second;
            fullValue = it->first + it2->first;
          }
        }
      }
    }
  }

  cout << fullValue;

}