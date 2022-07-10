#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int x = 0, y = 0;
  int dX, dY;
  scanf("%d %d\n", &dX, &dY);
  int q; scanf("%d\n", &q);
  vector<int> inst;
  while(q--)
  {
    string a; cin >> a;
    if(a == "Forward")
    {
      inst.push_back(0);
    }
    else if(a == "Right")
    {
      inst.push_back(1);
    }
    else if(a == "Left")
    {
      inst.push_back(2);
    }
  }

  vector<vector<int>> a({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
  int direction = 0;

  for(int i = 0; i < inst.size(); i++)
  {
    for(int k = 0; k < 3; k++)
    {
      int newX = x, newY = y, newDirection = direction;
      if(k == 0)
      {
        newX += a.at(direction).at(0);
        newY += a.at(direction).at(1);
      }
      else if(k == 1) newDirection = (direction+1)%4;
      else newDirection = (4+direction-1)%4;

      for(int j = i+1; j < inst.size(); j++)
      {
        if(inst.at(j) == 0)
        {
          newX += a.at(newDirection).at(0);
          newY += a.at(newDirection).at(1);
        }
        else if(inst.at(j) == 1)
        {
           newDirection = (newDirection+1)%4;
        }
        else
        {
           newDirection = (4+newDirection-1)%4;
        }
      }

      if(newX == dX && newY == dY)
      {
        if(k != inst.at(i))
        {
          cout << i+1 << " " << (k == 0 ? "Forward" : k == 1 ? "Right" : "Left");
          return 0;
        }
      }
    }
    if(inst.at(i) == 0)
    {
      x += a.at(direction).at(0);
      y += a.at(direction).at(1);
    }
    else if(inst.at(i) == 1)
    {
        direction = (direction+1)%4;
    }
    else
    {
        direction = (4+direction-1)%4;
    }
  }
}