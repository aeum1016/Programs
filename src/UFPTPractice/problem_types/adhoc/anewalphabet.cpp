#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main()
{
  unordered_map<char, string> m;
  m.emplace('a', "@");
  m.emplace('b', "8");
  m.emplace('c', "(");
  m.emplace('d', "|)");
  m.emplace('e', "3");
  m.emplace('f', "#");
  m.emplace('g', "6");
  m.emplace('h', "[-]");
  m.emplace('i', "|");
  m.emplace('j', "_|");
  m.emplace('k', "|<");
  m.emplace('l', "1");
  m.emplace('m', "[]\\/[]");
  m.emplace('n', "[]\\[]");
  m.emplace('o', "0");
  m.emplace('p', "|D");
  m.emplace('q', "(,)");
  m.emplace('r', "|Z");
  m.emplace('s', "$");
  m.emplace('t', "']['");
  m.emplace('u', "|_|");
  m.emplace('v', "\\/");
  m.emplace('w', "\\/\\/");
  m.emplace('x', "}{");
  m.emplace('y', "`/");
  m.emplace('z', "2");

  string line;
  string out;
  // char temp[1];
  // char c = cin.peek();
  // cout << string(5, ' ');
  // while(!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'))
  // {
  //   cin.read(temp, 1);
  //   out += c;
  //   c = cin.peek();
  //   cout << " ";
  // }

  getline(cin, line);

  for(char c : line)
  {
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
      if(c<='Z') out.append(m.at(c + 'a' - 'A'));
      else out.append(m.at(c));
    }
    else 
      out += c;
  }
  cout << out;
  return 0;
}