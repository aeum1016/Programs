#include <stack>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);
  int i = 0;
  stack<char> a;
  while(i < q)
  {
    char c; scanf("%c", &c);
    if(c == '[' || c == '{' || c == '(')
    {
      a.push(c);
    }
    else if(c == ']')
    {
      if(!a.empty() && a.top() == '[') a.pop();
      else 
      {
        cout << c << " " << i;
        return 0;
      }
    }
    else if(c == '}')
    {
      if(!a.empty() && a.top() == '{') a.pop();
      else 
      {
        cout << c << " " << i;
        return 0;
      }
    }
    else if(c == ')')
    {
      if(!a.empty() && a.top() == '(') a.pop();
      else 
      {
        cout << c << " " << i;
        return 0;
      }
    }
    i++;
  }
  cout << "ok so far";
  return 0;
}