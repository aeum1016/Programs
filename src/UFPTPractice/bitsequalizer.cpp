#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main()
{
  int q; scanf("%d", &q);
  int j = 1;
  while(j <= q)
  {
    string s, t; cin >> s >> t;
    int outOfPlace1 = 0, outOfPlace0 = 0, q0 = 0, q1 = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
      char c = s.at(i);
      if(c != t.at(i))
      {
        if(c == '1') outOfPlace1++;
        else if (c== '0') outOfPlace0++;
        else if(t.at(i) == '1') q1++;
        else q0++;
      }
    }
    printf("Case %d: ", j);
    if(outOfPlace1 > outOfPlace0+q1)
    {
      printf("-1\n");
    }
    else
    {
      int switches = outOfPlace1 + (outOfPlace0 > outOfPlace1 ? fmax(q0, outOfPlace0) : 0);
      int flips = q0 + q1 + (outOfPlace0 > outOfPlace1 ? outOfPlace0 - fmax(q0, outOfPlace0) - outOfPlace1 : 0);
      printf("%d\n", switches + flips);
    }
    j++;
  }
  return 0;
}