#include <bits/stdc++.h>

using namespace std;

int main()
{
  stack<int> a;
  stack<int> b;

  int p; scanf("%d", &p);

  while(p--)
  {
    int o, t;
    scanf("%d %d", &o, &t);
    a.push(o);
    a.push(t);
  }

  int moves = 0;
  while(true)
  {
    if(!a.empty() && !b.empty() && a.top() == b.top())
    {
      a.pop();
      b.pop();
    }
    else if(!a.empty())
    {
      b.push(a.top());
      a.pop();
    }
    else
    {
      break;
    }
    moves++;
  }
  if(b.empty()) cout << moves;
  else cout << "impossible";
  return 0;
}