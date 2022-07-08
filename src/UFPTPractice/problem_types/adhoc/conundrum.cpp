#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  string str;
  cin >> str;
  char per[3] = {'P', 'E', 'R'};
  int i = 0;
  int changes = 0;
  for(char c : str)
  {
    if(c != per[i]) changes++;
    i = (i+1)%3;
  }
  cout << changes;
}