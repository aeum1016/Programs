#include <stack>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int c, q;
  scanf("%d %d\n", &c, &q);
  int pos = 0;
  stack<int> prev;
  while(q--)
  {
    string a;
    cin >> a;
    if(a == "undo")
    {
      int b; cin >> b;
      int newPos;
      while(b--)
      {
        newPos = prev.top();
        prev.pop();
      }
      pos = newPos;
    }
    else
    {
      int b = stoi(a);
      int newPos = (pos + b);
      while(newPos < 0)
      {
        newPos+=c;
      }
      newPos%=c;
      prev.push(pos);
      pos = newPos;
    }
  }
  cout << pos;
  return 0;
}