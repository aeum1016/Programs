#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  int q;
  while(scanf("%d", &q) != EOF)
  {
    vector<bool> found(q, false);
    int cur, prev = 300001;
    bool jolly = true;
    int i = 0;
    while(i < q)
    {
      scanf("%d", &cur);
      if(prev != 300001)
      {
        int dif = abs(cur - prev);
        if(dif > q-1 || found.at(dif)) jolly = false;
        else found[dif] = true;
      }
      prev = cur;
      i++;
    }
    printf("%s\n", jolly ? "Jolly" : "Not jolly");
  }
  return 0;
}