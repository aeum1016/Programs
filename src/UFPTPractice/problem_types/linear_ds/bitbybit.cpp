#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int q;
  while(scanf("%d\n", &q) != EOF)
  {
    if(q == 0) return 0;
    vector<int> bits(32, -1); 
    while(q--)
    {
      string s;
      cin >> s;
      int bit1, bit2;
      cin >> bit1;
      if(s == "OR" || s == "AND") cin >> bit2;

      if(s == "SET") bits[31-bit1] = 1;
      else if(s == "CLEAR") bits[31-bit1] = 0;
      else if(s == "OR")
      {
        if(bits[31-bit1] == 1 || bits[31-bit2] == 1) bits[31-bit1] = 1;
        else if(bits[31-bit1] == 0 && bits[31-bit2] == 0) bits[31-bit1] = 0;
        else bits[31-bit1] = -1;
      }
      else if(s == "AND")
      {
        if(bits[31-bit1] == 0 || bits[31-bit2] == 0) bits[31-bit1] = 0;
        else if(bits[31-bit1] == 1 && bits[31-bit2] == 1) bits[31-bit1] = 1;
        else bits[31-bit1] = -1;
      }
    }
    for(int i : bits)
    {
      if(i == -1) cout << '?';
      else cout << i;
    }
    cout << endl;
  }
}