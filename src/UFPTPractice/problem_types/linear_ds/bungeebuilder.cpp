#include <stdio.h>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int max = -1;
  int curMin = (1E9)+1;
  int curDif = 0;
  int q; scanf("%d", &q);
  while(q--)
  {
    int a; scanf("%d", &a);
    if(a >= max)
    {
      if(max - curMin > curDif)
      {
        curDif = max - curMin;
      }
      max = a;
      curMin = (1E9)+1;
    }
    else if(a <= curMin)
    {
      curMin = a;
    }
    else if(a - curMin > curDif)
    {
      curDif = a-curMin;
    }
  }
  cout << curDif;
  return 0;
}