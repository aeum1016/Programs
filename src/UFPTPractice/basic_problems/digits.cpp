#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  string s;
  while(true)
  {
    cin >> s;
    if(s == "END") break;
    string prev = "";
    int i = 0;
    while(prev != s)
    {
      prev = s;
      s = to_string(s.length());
      i++;
    }
    printf("%d\n", i);
  } 

  return 0;
}