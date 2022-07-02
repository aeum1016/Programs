#include <stdio.h>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  int h; scanf("%d ", &h);
  h*=4;
  char d; scanf("%c", &d);
  string temp;
  getline(cin , temp);

  int points = 0;

  unordered_map<char, int> vals;
  vals.emplace('A', 11);
  vals.emplace('K', 4);
  vals.emplace('Q', 3);
  vals.emplace('j', 20);
  vals.emplace('J', 2);
  vals.emplace('T', 10);
  vals.emplace('1', 14);
  vals.emplace('9', 0);

  while(h--)
  {
    string v; 
    cin >> v;
    if(v.at(0) == 'J' || v.at(0) == '9')
    {
      if(v.at(1) == d)
      {
        points += vals.at(v.at(0) == 'J' ? 'j' : '1');
      }
      else
      {
        points += vals.at(v.at(0));
      }
    }
    else
    {
      if(vals.find(v.at(0)) != vals.end())
      {
        points += vals.at(v.at(0));
      }
    }
  }
  printf("%d", points);
  return 0;
}