#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  int q; scanf("%d", &q);
  int i = 0;
  while(i++ < q)
  {
    int a, b; scanf("%d %d", &a, &b);
    cout << "Case #" << i << ": ";
    cout << (((int)pow(2, a)-1 & b) == ((int)pow(2, a)-1) ? "ON" : "OFF") << endl;
  }
  return 0;
}