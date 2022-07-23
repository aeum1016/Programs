#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
  int q;
  while(scanf("%d\n", &q) != EOF)
  {
    if(!q) return 0;
    int a = 0;
    int b = 0;
    bool aStack = true;
    while(q--)
    {
      string c; int d;
      cin >> c >> d;
      if(c == "DROP")
      {
        a+=d;
        cout << "DROP 1 " << d << endl;
      }
      else
      {
        int initialB = b;
        if(b)
        {
          if(d > b)
          {
            cout << "TAKE 2 " << b << endl;
            b = 0;


            cout << "MOVE 1->2 " << a << endl;
            b = a;
            a = 0;
            
            cout << "TAKE 2 " << (d-initialB) << endl;
            b -= (d-initialB);
          }
          else
          {
            cout << "TAKE 2 " << d << endl;
            b -= d;
          }
        }
        else
        {
          cout << "MOVE 1->2 " << a << endl;
          b = a;
          a = 0;
          
          cout << "TAKE 2 " << d << endl;
          b -= d;
        }
      }
    }
    cout << endl;
  }
}