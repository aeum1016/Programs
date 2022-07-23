#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);
  vector<bool> b;
  for(int i = 0; i < q; i++)
  {
    char c; scanf("%c ", &c);
    b.push_back((c == 'T' ? 1 : 0));
  }
  stack<bool> a;
  char c;
  while(scanf("%c ", &c) != EOF)
  {
    if(c >= 'A' && c <= 'Z')
    {
      a.push(b.at(c-'A'));
    }
    else
    {
      if(c == '*')
      {
        bool d = a.top();
        a.pop();
        bool e = a.top();
        a.pop();
        a.push(d && e);
      }
      else if(c == '+')
      {
        bool d = a.top();
        a.pop();
        bool e = a.top();
        a.pop();
        a.push(d || e);
      }
      else if(c == '-')
      {
        bool d = a.top();
        a.pop();
        a.push(!d);
      }
    }
  }
  cout << (a.top() ? "T" : "F");
  return 0;
}