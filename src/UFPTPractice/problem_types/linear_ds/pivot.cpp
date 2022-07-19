#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
  int q; scanf("%d", &q);
  stack<int> nums;
  long long max = -1E12;
  while(q--)
  {
    int a; scanf("%d", &a);
    if(a > max)
    {
      max = a;
      nums.push(a);
    }
    else
    {
      while(!nums.empty() && a < nums.top())
      {
        nums.pop();
      }
    }
  }

  cout << nums.size();

  return 0;
}