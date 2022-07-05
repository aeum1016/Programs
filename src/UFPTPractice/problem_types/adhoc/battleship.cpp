#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

bool playerDead(vector<bool> &ships)
{
    bool down = true;
    for(bool ship : ships)
    {
      if(ship) down = false;
    }

    return down;
}

int main()
{
  int t; scanf("%d", &t);
  while(t--)
  {

    int w, h, n; scanf("%d %d %d\n", &w, &h, &n);

    vector<bool> p1Ships(w*h);
    vector<bool> p2Ships(w*h);

    for(int y = h-1; y >= 0; y--)
    {
      for(int x = 0; x < w; x++)
      {
        char c; cin >> c;
        if(c=='#') p1Ships[y*w + x] = true;
      }
    }
    for(int y = h-1; y >= 0; y--)
    {
      for(int x = 0; x < w; x++)
      {
        char c; cin >> c;
        if(c=='#') p2Ships[y*w + x] = true;
      }
    }

    bool p1Turn = true;
    bool lastTurn = false;
    bool gameOver = false;
    for(int i = 0; i < n; i++)
    {
      int x, y; scanf("%d %d\n", &x, &y);
      if(p1Turn)
      {
        if(!gameOver)
        {
          if(p2Ships[y*w + x]) 
          {
            p2Ships[y*w + x] = false;
            if(playerDead(p2Ships)) 
            {
              lastTurn = true;
              p1Turn = false;
            }
          }
          else{
            p1Turn = false;
            if(lastTurn) gameOver = true;
          }
        }
      }
      else
      {
        if(!gameOver)
        {
          if(p1Ships[y*w + x]) 
          {
            p1Ships[y*w + x] = false;
            if(playerDead(p1Ships))
            {
              gameOver = true;
            }
          }
          else{
            p1Turn = true;
            if(lastTurn) gameOver = true;
          }
        }
      }
    }
    bool p1Down = playerDead(p1Ships);
    bool p2Down = playerDead(p2Ships);

    if(p1Down == p2Down)
    {
      printf("draw\n");
    }
    else if(p1Down)
    {
      printf("player two wins\n");
    }
    else printf("player one wins\n");
  }
}