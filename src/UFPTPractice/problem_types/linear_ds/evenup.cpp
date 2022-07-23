#include <bits/stdc++.h>

using namespace std;

int main()
{
  stack<int> stack;
  int q; scanf("%d", &q);
  while(q--)
  {
    int a; scanf("%d", &a);
    if(stack.empty())
    {
      stack.push(a);
    }
    else
    {
      if((stack.top() + a)%2)
      {
        stack.push(a);
      }
      else stack.pop();
    }
  }
  cout << stack.size();
  return 0;
}