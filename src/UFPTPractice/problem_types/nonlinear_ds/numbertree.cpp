#include <bits/stdc++.h>

using namespace std;

int main()
{
  int h; cin >> h;
  int i = 1;
  string s;
  cin >> s;
  for(char c : s)
  {
    if(c == 'R')
    {
      i <<= 1;
      i++;
    }
    else if(c == 'L')
    {
      i <<= 1;
    }
  }
  cout << (int)pow(2, h+1) - i;
}