#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  unordered_map<char, string> mapping;
  mapping.emplace('a', "2");
  mapping.emplace('b', "22");
  mapping.emplace('c', "222");
  mapping.emplace('d', "3");
  mapping.emplace('e', "33");
  mapping.emplace('f', "333");
  mapping.emplace('g', "4");
  mapping.emplace('h', "44");
  mapping.emplace('i', "444");
  mapping.emplace('j', "5");
  mapping.emplace('k', "55");
  mapping.emplace('l', "555");
  mapping.emplace('m', "6");
  mapping.emplace('n', "66");
  mapping.emplace('o', "666");
  mapping.emplace('p', "7");
  mapping.emplace('q', "77");
  mapping.emplace('r', "777");
  mapping.emplace('s', "7777");
  mapping.emplace('t', "8");
  mapping.emplace('u', "88");
  mapping.emplace('v', "888");
  mapping.emplace('w', "9");
  mapping.emplace('x', "99");
  mapping.emplace('y', "999");
  mapping.emplace('z', "9999");
  mapping.emplace(' ', "0");

  int q;
  string queries;
  getline(cin, queries, '\n');
  q = stoi(queries);
  int i = 0;
  string str;

  while(q--)
  {
    i++;
    string out = "";
    getline(cin, str, '\n');
    for(char c : str)
    {
      if(out.size() > 0 && out.at(out.size()-1) == mapping.at(c).at(0))
      {
        out.append(" ");
      }
      out.append(mapping.at(c));
    }
    cout << "Case #" << i << ": " << out << "\n";
  }
  return 0;
}