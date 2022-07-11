#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Box
{
  public:
    Box(int x, int y, int w, int h)
    {
      this->x = x;
      this->y = y;
      this->w = w;
      this->h = h;
    }
    int x, y;
    int w, h;
    void move(int xDelta, int yDelta)
    {
      x+=xDelta;
      y+=yDelta;
    }
    void resize(int newW, int newH)
    {
      w = newW;
      h = newH;
    }
    bool overlaps(int nX, int nY, int nW, int nH)
    {
      if(nX > x && nY > y && nX < x+w && nY < y+h) return true;
      if(nX > x && nY+nH > y && nX < x+w && nY+nH < y+h) return true;
      if(nX+nW > x && nY > y && nX+nW < x+w && nY+nH < y+h) return true;
      if(nX+nW > x && nY+nH > y && nX+nW < x+w && nY+nH < y+h) return true;
      return false;
    }
    bool contains(int nX, int nY)
    {
      if(nX >= x && nY >= y && nX <= x+w && nY <= y+h) return true;
      return false;
    }
};

class Window
{
  public:
    Window(int x, int y)
    {
      wX = x;
      wY = y;
    }
    int wX, wY;
    vector<Box*> boxes;
    bool openBox(int x, int y, int w, int h)
    {
      if(x >= 0 && y >= 0 && x+w <= wX && y+h <= wY)
      {
        bool overlap = false;
        for(Box* b : boxes)
        {
          if(b->overlaps(x, y, w, h)) overlap = true;
        }
        if(overlap) return false;
      }
      else return false;
      Box* b = new Box(x, y, w, h);
      boxes.push_back(b);
      return true;
    }

    bool closeBox(int x, int y)
    {
      for(Box* b : boxes)
      {
        if(b->contains(x, y))
        {
          int index = find(boxes.begin(), boxes.end(), b)-boxes.begin();
          boxes.erase(find(boxes.begin(), boxes.end(), b));
          return true;
        }
      }
      return false;
    }

    bool resizeBox(int x, int y, int w, int h)
    {
      for(Box* b : boxes)
      {
        if(b->contains(x, y))
        {
          int index = find(boxes.begin(), boxes.end(), b)-boxes.begin();
          for(int i = 0; i < boxes.size(); i++)
          {
            if(i != index && (boxes.at(i)->overlaps(b->x, b->y, w, h)))
            {
              return false;
            }
          }
          b->resize(w, h);
          return true;
        }
      }
      return false;
    }

    bool moveBox(int x, int y, int mX, int mY)
    {
      for(Box* b : boxes)
      {
        if(b->contains(x, y))
        {
          int index = find(boxes.begin(), boxes.end(), b)-boxes.begin();
          for(int i = 0; i < boxes.size(); i++)
          {
            if(i != index && (boxes.at(i)->overlaps(b->x+mX, b->y+mY, b->w, b->h)))
            {
              // moveBox(boxes.at(i)->x, boxes.at(i)->y, boxes.at(i).x - b->x+mX+(mX > 0 ? b->w : 0), boxes.at(i).y-(b->y+mY+(mY > 0 ? b->h: 0)));
            }
          }
          b->move(w, h);
          return true;
        }
      }
      return false;
    }
};


int main()
{
  Window w(320, 200);
  cout << w.openBox(50, 50, 10, 10) << endl;
  cout << w.openBox(70, 55, 10, 10) << endl;
  cout << w.openBox(90, 55, 10, 10) << endl;
  cout << w.resizeBox(55, 55, 20, 10) << endl;
  cout << w.closeBox(110, 60) << endl;
}