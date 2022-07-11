#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Lane
{
  public:
    Lane(int w, int o, int i, int s, bool r, int l)
    {
      spacing = i;
      laneNum = l;
      width = w;
      if(r)
      {
        speed = s;
        right = r;
        car = o;
      }
      else
      {
        speed = -s;
        right = r;
        car = w-1-o;
      }
    }
    bool simulate(int x, int y, char c)
    {
      if(speed == 0)
      {
        for(int j = car; j < width; j+=spacing)
        {
          if(j == x && laneNum == y) return true;
        }
        for(int j = car; j >= 0; j-=spacing)
        {
          if(j == x && laneNum == y) return true;
        }
      }
      for(int i = 0; i < abs(speed); i++)
      {
        if(right)
        {
          car=car+1;
          if(car >= width) 
          {
            car-=spacing;
          }
          for(int j = car; j < width; j+=spacing)
          {
            if(j == x && laneNum == y) return true;
            if(j == x+1 && laneNum == y && c == 'L') return true;
          }
          for(int j = car; j >= 0; j-=spacing)
          {
            if(j == x && laneNum == y) return true;
            if(j == x+1 && laneNum == y && c == 'L') return true;
          }
        }
        else
        {
          car=car-1;
          if(car < 0) car+=spacing;
          for(int j = car; j < width; j+=spacing)
          {
            if(j == x && laneNum == y) return true;
            if(j == x-1 && laneNum == y && c == 'R') return true;
          }
          for(int j = car; j >= 0; j-=spacing)
          {
            if(j == x && laneNum == y) return true;
            if(j == x-1 && laneNum == y && c == 'R') return true;
          }
        }
      }
      return false;
    }
    private:
      int width;
      int car;
      int spacing;
      int speed;
      int laneNum;
      bool right;
};

int main()
{
  int l, w; scanf("%d %d\n", &l, &w);
  int j = 0;
  vector<Lane*> lanes;
  while(j < l)
  {
    int o, i, s;
    scanf("%d %d %d\n", &o, &i, &s);
    Lane* l = new Lane(w, o, i, s, !(j%2), j);
    lanes.push_back(l);
    j++;
  }
  int x, y = lanes.size();
  cin >> x;
  string instructions;
  cin >> instructions;
  for(char c : instructions)
  {
    // cout << x << " " << y << endl;
    //make move
    if(c == 'U') y--;
    else if(c == 'R') x++; 
    else if(c == 'L') x--;
    else y++;
    //simulate movement
    for(Lane* l : lanes)
    {
      bool crash = l->simulate(x, y, c);
      if(crash)
      {
        cout << "squish";
        return 0;
      }
    }
  }
  if(y <= -1) cout << "safe";
  else cout << "squish";
  return 0;
}