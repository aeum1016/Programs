#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int w, h;
  int house = 1;
  while(scanf("%d %d\n", &w, &h) != EOF)
  {
    if(w == 0 && h == 0) return 0;
    vector<vector<char>> room(h, vector<char>(w));
    int x, y;
    for(int i = 0; i < h; i++)
    {
      for(int j = 0; j < w; j++)
      {
        char c; scanf("%c", &c);
        if(c == '*')
        {
          x = j;
          y = i;
        }
        room.at(i)[j] = c;
      }
      char t; scanf("%c", &t);
    }


    int direction = 0;
    vector<int> xDir = {1, 0, -1, 0};
    vector<int> yDir = {0, 1, 0, -1};

    if(x == 0) direction = 0;
    else if(y == 0) direction = 1;
    else if(x == w-1) direction = 2;
    else direction = 3;

    while(room.at(y).at(x) != 'x')
    {
      x+=xDir.at(direction);
      y+=yDir.at(direction);

      if(room.at(y).at(x) == '/')
      {
        if(direction == 0) direction = 3;
        else if(direction == 3) direction = 0;
        else if(direction == 1) direction = 2;
        else if(direction == 2) direction = 1;
      }
      else if(room.at(y).at(x) == '\\')
      {
        if(direction == 0) direction = 1;
        else if(direction == 1) direction = 0;
        else if(direction == 2) direction = 3;
        else if(direction == 3) direction = 2;
      }
    }

    room.at(y)[x] = '&';
    cout << "HOUSE " << house << endl;
    for(int i = 0; i < h; i++)
    {
      for(int j = 0; j < w; j++)
      {
        cout << room.at(i).at(j);
      }
      cout << endl;
    }
    house++;
  }
}
