#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
  string line; getline(cin, line);
  stringstream liness(line);
  string name;
  while(getline(liness, name, '-'))
  {
    cout << name.at(0);
  }
  return 0;
}