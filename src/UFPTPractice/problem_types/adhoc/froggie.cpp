#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Lane
{
  public:
    Lane(int w, int o, int i, int s, bool r)
    {
      spacing = i;
      if(right)
      {
        speed = s;
        right = r;
        for(int j = o; j < w; j+=i)
        {
          cars.push_back(j);
        }
      }
      else
      {
        speed = -s;
        right = r;
        for(int j = w-1-o; j >= 0; j-=i)
        {
          cars.push_back(j);
        }
      }
    }
    int w;
    vector<int> cars;
    int spacing;
    int speed;
    bool right;
};

int main()
{
  int l, w; scanf("%d %d\n", &l, &w);
  int j = 0;
  vector<Lane> lanes;
  while(j < l)
  {
    int o, i, s;
    scanf("%d %d %d\n", &o, &i, &s);
    printf("%d %d %d %d %d\n", w, o, i, s, !(j%2));
    lanes.push_back(Lane(w, o, i, s, !(j%2)));
    j++;
  }
  int x, y = 0;
  cin >> x;
  string instructions;
  cin >> instructions;
  cout << instructions;
  for(char c : instructions)
  {
    //make move
    if(c == 'U') y++;
    else if(c == 'R') x++; 
    else if(c == 'L') x--;
    else y--;
    //simulate movement
    //end if crash or finished
  }
}