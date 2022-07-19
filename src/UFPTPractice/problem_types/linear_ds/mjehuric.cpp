#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> a;
  for(int i = 0; i < 5; i++)
  {
    int b; scanf("%d", &b);
    a.push_back(b);
  }

  vector<int> sorted({1, 2, 3, 4, 5});
  int spot = 0;
  while(a != sorted)
  {
    if(a.at(spot) > a.at(spot+1))
    {
      int temp = a.at(spot+1);
      a[spot+1] = a.at(spot);
      a[spot] = temp;
      for(int i : a)
      {
        cout << i << " ";
      }
      cout << endl;
    }
    spot = (spot+1) % 4;
  }
}