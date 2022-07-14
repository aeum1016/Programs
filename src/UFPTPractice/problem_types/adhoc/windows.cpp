#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

class Box
{
  public:
    int x, y;
    int w, h;
    int index;
    Box(int x, int y, int w, int h, int c)
    {
      this->x = x;
      this->y = y;
      this->w = w;
      this->h = h;
      this->index = c;
    }
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
      Box b(nX, nY, nW, nH, -1);
      if(this->x+this->w <= b.x) return false;
      if(b.x+b.w <= this->x) return false;
      if(this->y+this->h <= b.y) return false;
      if(b.y+b.h <= this->y) return false;
      return true;
    }

    bool contains(int nX, int nY)
    {
      if(nX >= x && nY >= y && nX < x+w && nY < y+h) return true;
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
    int counter = 0;
    int boxSize()
    {
      return boxes.size();
    }

    bool sortAsc(Box* a, Box* b)
    {
      return (a->x < b->x);
    }

    void printBoxes()
    {
      for(Box* b : boxes)
      {
        cout << b->x << " " << b->y << " " << b->w << " " << b->h << endl;
      }
    }

    int openBox(int x, int y, int w, int h)
    {
      if(!outOfBounds(x, y, w, h))
      {
        bool overlap = false;
        for(Box* b : boxes)
        {
          if(b->overlaps(x, y, w, h)) overlap = true;
        }
        if(overlap) return 1;

        Box* b = new Box(x, y, w, h, counter);
        counter++;
        boxes.push_back(b);
        return 0;
      }
      else return 1;
    }

    int closeBox(int x, int y)
    {
      for(Box* b : boxes)
      {
        if(b->contains(x, y))
        {
          boxes.erase(find(boxes.begin(), boxes.end(), b));
          return 0;
        }
      }
      return 2;
    }

    int resizeBox(int x, int y, int w, int h)
    {
      for(Box* b : boxes)
      {
        if(b->contains(x, y))
        {
          if(outOfBounds(b->x, b->y, w, h)) return 1;
          int index = find(boxes.begin(), boxes.end(), b)-boxes.begin();
          for(int i = 0; i < boxes.size(); i++)
          {
            if(i != index && (boxes.at(i)->overlaps(b->x, b->y, w, h)))
            {
              return 1;
            }
          }
          b->resize(w, h);
          return 0;
        }
      }
      return 2;
    }

    bool outOfBounds(int x, int y, int w, int h)
    {
      return !(x >= 0 && y >= 0 && x+w <= wX && y+h <= wY);
    }

    vector<int> dX = vector<int>({1,0,-1,0});
    vector<int> dY = vector<int>({0,1,0,-1});

    int getDir(int dx, int dy)
    {
      int x = dx/abs(dx+dy);
      int y = dy/(abs(dx+dy));
      for(int i = 0; i < dX.size(); i++)
      {
        if(x == dX[i] && y == dY[i]) return i;
      }
      return -1;
    }

    int distToBorder(int dir, int bIndex)
    {
      if(dir == 0) return wX - (boxes.at(bIndex)->x + boxes.at(bIndex)->w);
      else if(dir == 1) return wY - (boxes.at(bIndex)->y + boxes.at(bIndex)->h);
      else if(dir == 2) return boxes.at(bIndex)->x;
      else if(dir == 3) return boxes.at(bIndex)->y;
      return -1;
    }

    int distBetween(int sIndex, int dIndex, int dir)
    {
      Box s = *boxes.at(sIndex);
      Box d = *boxes.at(dIndex);
      if(dir%2 == 0)
      {
        if(s.y >= d.y+d.h || s.y+s.h <= d.y) return -1;
        if(dir == 0)
        {
          if(s.x + s.w > d.x) return -1;
          else return d.x - (s.x + s.w);
        }
        if(s.x < d.x+d.w) return -1;
        else return s.x - (d.x + d.w);
      }
      else
      {
        if(s.x >= d.x+d.w || s.x+s.w <= d.x) return -1;
        if(dir == 1)
        {
          if(s.y+s.h > d.y) return -1;
          else return d.y - (s.y+s.h);
        }
        if(s.y < d.y+d.h) return -1;
        else return s.y - (d.y+d.h);
      }
      return -1;
    }

    int moveBox(int x, int y, int mX, int mY)
    {
      //dijkstras, following Arup Guha from UCF's solution
      int maxMove = fmax(abs(mX), abs(mY));
      int orgMove = maxMove;
      int dir = getDir(mX, mY);

      //store distances for Dijkstras
      vector<int> dist(boxes.size(), -1);
      vector<int> used(boxes.size(), false);
      Box* first = nullptr;
      for(Box* b : boxes)
      {
        if(b->contains(x, y))
        {
          first = b;
          break;
        }
      }
      if(first == nullptr) return (1E9)+1;
      int index = find(boxes.begin(), boxes.end(), first) - boxes.begin();
      dist[index] = 0;

      while(true)
      {
        //Find next best item
        int best = -1, bestD = (1E9)+1;
        for(int i = 0; i < boxes.size(); i++)
        {
          if(dist[i] != -1 && dist[i] < bestD && !used[i])
          {
            bestD = dist[i];
            best=i;
          }
        }
        if(best == -1 || bestD > maxMove) break;
        used[best] = true;

        maxMove = fmin(maxMove, distToBorder(dir, best) + dist[best]);

        for(int i = 0; i < boxes.size(); i++)
        {
          if(i == best) continue;
          
          if(distBetween(best, i, dir) != -1)
          {
            if(dist[i] == -1 || dist[best] + distBetween(best, i, dir) < dist[i])
            {
              dist[i] = dist[best] + distBetween(best, i, dir);
            }
          }
        }
      }

      for(int i = 0; i < boxes.size(); i++)
      {
        if(dist[i] != -1 && dist[i] < maxMove)
        {
          int toMove = maxMove - dist[i];
          boxes[i]->move(dX[dir]*toMove, dY[dir]*toMove);
        }
      }
      return maxMove;
    }
};


int main()
{
  int x, y;
  scanf("%d %d/n", &x, &y);
  Window w(x, y);
  string command;
  int cNum = 0;
  while(getline(cin, command))
  {
    string commandP;
    stringstream commandSS(command);
    vector<string> com(5);
    int i = 0;
    while(getline(commandSS, commandP, ' '))
    {
      com[i] = commandP;
      i++;
    }
    int result = 0;
    if(com[0] == "OPEN")
    {
      result = w.openBox(stoi(com[1]), stoi(com[2]), stoi(com[3]), stoi(com[4]));
    }
    else if(com[0] == "CLOSE")
    {
      result = w.closeBox(stoi(com[1]), stoi(com[2]));
    }
    else if(com[0] == "RESIZE")
    {
      result = w.resizeBox(stoi(com[1]), stoi(com[2]), stoi(com[3]), stoi(com[4]));
    }
    else if(com[0] == "MOVE")
    {
      result = w.moveBox(stoi(com[1]), stoi(com[2]), stoi(com[3]), stoi(com[4]));
    }
    if(com[0] != "MOVE")
    {
      if(result == 1) cout << "Command " << cNum << ": " << com[0] << " - window does not fit" << endl;
      else if(result == 2) cout << "Command " << cNum << ": " << com[0] << " - no window at given position" << endl;
    }
    else
    {
      if(abs(result) != fmax(abs(stoi(com[3])), abs(stoi(com[4]))))
      {
        if(result == (1E9)+1) cout << "Command " << cNum << ": " << com[0] << " - no window at given position" << endl;
        else cout << "Command " << cNum << ": " << com[0] << " - moved " << abs(result) << " instead of " << abs(stoi(com[3]) ? stoi(com[3]) : stoi(com[4])) << endl;
      }
    }
    cNum++;
  }
  cout << w.boxSize() << " window(s):" << endl;
  w.printBoxes();
}