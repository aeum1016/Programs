#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  string possibility = "1234567890";

  string guess;
  string remark; 
  while(getline(cin, guess))
  {
    getline(cin, remark);
    if(remark == "right on")
    {
      if(possibility.find((guess.size() == 2 ? '0' : guess.at(0))) != string::npos)
      {
        printf("Stan may be honest\n");
      }
      else printf("Stan is dishonest\n");
      possibility = "1234567890";
    }
    else
    {
      int g = stoi(guess);
      if(remark == "too high")
      {
        for(int i = g; i <= 10; i++)
        {
          if(possibility.find(to_string(i).size() == 2 ? '0' : to_string(i).at(0)) != string::npos)
          {
            possibility.erase(possibility.find(to_string(i).size() == 2 ? '0' : to_string(i).at(0)), 1);
          }
        }
      }
      else
      {
        for(int i = g; i > 0; i--)
        {
          if(possibility.find(to_string(i).size() == 2 ? '0' : to_string(i).at(0)) != string::npos)
          {
            possibility.erase(possibility.find(to_string(i).size() == 2 ? '0' : to_string(i).at(0)), 1);
          }
        }
      }
    }
  }
}