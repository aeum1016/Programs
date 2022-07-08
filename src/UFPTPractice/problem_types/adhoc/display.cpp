#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
  unordered_map<char, vector<string>> trans;
  trans.emplace('0', vector<string>({"+---+", "|   |", "|   |", "+   +", "|   |", "|   |", "+---+"}));
  trans.emplace('1', vector<string>({"    +", "    |", "    |", "    +", "    |", "    |", "    +"}));
  trans.emplace('2', vector<string>({"+---+", "    |", "    |", "+---+", "|    ", "|    ", "+---+"}));
  trans.emplace('3', vector<string>({"+---+", "    |", "    |", "+---+", "    |", "    |", "+---+"}));
  trans.emplace('4', vector<string>({"+   +", "|   |", "|   |", "+---+", "    |", "    |", "    +"}));
  trans.emplace('5', vector<string>({"+---+", "|    ", "|    ", "+---+", "    |", "    |", "+---+"}));
  trans.emplace('6', vector<string>({"+---+", "|    ", "|    ", "+---+", "|   |", "|   |", "+---+"}));
  trans.emplace('7', vector<string>({"+---+", "    |", "    |", "    +", "    |", "    |", "    +"}));
  trans.emplace('8', vector<string>({"+---+", "|   |", "|   |", "+---+", "|   |", "|   |", "+---+"}));
  trans.emplace('9', vector<string>({"+---+", "|   |", "|   |", "+---+", "    |", "    |", "+---+"}));
  trans.emplace(':', vector<string>({" ", " ", "o", " ", "o", " ", " "}));
  
  string a; 

  while(getline(cin, a))
  {
    if(a.at(0) == 'e')
    {
      cout << "end\n";
      break;
    }
    for(int i = 0; i < 7; i++)
    {
      for(int j = 0; j <= 4; j++)
      {
        cout << trans.at(a.at(j)).at(i);
        if(j != 4) cout << "  ";
      }
      cout << endl;
    }
    cout << endl << endl;
  }
  return 0;
}