#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  string line;
  vector<vector<int>> dots(62);
  int x = 0;
  int y = 0;
  while(getline(cin, line))
  {
    if(line == "")
    {
      vector<vector<bool>> hori(x, vector<bool>(y, false));
      vector<vector<bool>> vert(x, vector<bool>(y, false));
      vector<vector<int>> dotCoords(x, vector<int>(y, false));

      for(int i = 0; i < dots.size(); i++)
      {
        if(dots.at(i).empty()) break;
        dotCoords[dots.at(i)[0]][dots.at(i)[1]] = i+1;
        if(!i) continue;

        if(dots[i][0] == dots[i-1][0])
        {
          for(int j = fmin(dots[i][1],dots[i-1][1]); j < fmax(dots[i][1], dots[i-1][1]); j++)
          {
            hori.at(dots[i][0]).at(j) = true;
          }
        }
        else
        {
          for(int j = fmin(dots[i][0],dots[i-1][0]); j < fmax(dots[i][0], dots[i-1][0]); j++)
          {
            vert.at(j).at(dots[i][1]) = true;
          }
        }
      }
      for(int i = 0; i < x; i++)
      {
        for(int j = 0; j < y; j++)
        {
          char cur;
          if(dotCoords.at(i).at(j))
          {
            int c = dotCoords.at(i).at(j);
            if(c >= 1 && c <= 10) cur = (char)((c-1) +'0');
            else if(c >= 11 && c <= 36) cur = (char)((c-11) + 'a');
            else cur = (char)(c-37+'A');
          }
          else if(hori.at(i).at(j) && vert.at(i).at(j))
          {
            cur = '+';
          }
          else if(hori.at(i).at(j))
          {
            cur = '-';
          }
          else if(vert.at(i).at(j))
          {
            cur = '|';
          }
          else
          {
            cur = '.';
          }
          cout << cur;
        }
        cout << endl;
      }
      cout << endl;
      dots = vector<vector<int>>(62);
      x=0;
      continue;
    }
    else
    {
      y = 0;
      for(char i : line)
      {
        int num;
        if(i != '.')
        {
          if(i >= '0' && i <= '9') num = i - '0';
          else if(i >= 'a' && i <= 'z') 
          {
            int a = (int)(i-'a');
            num = 10 + a;
          }
          else num = 36 + (int)(i-'A');
          dots[num] = {x, y};
        }
        y++;
      }
    }
    x++;
  }


  vector<vector<bool>> hori(x, vector<bool>(y, false));
  vector<vector<bool>> vert(x, vector<bool>(y, false));
  vector<vector<int>> dotCoords(x, vector<int>(y, false));

  for(int i = 0; i < dots.size(); i++)
  {
    if(dots.at(i).empty()) break;
    dotCoords[dots.at(i)[0]][dots.at(i)[1]] = i+1;
    if(!i) continue;

    if(dots[i][0] == dots[i-1][0])
    {
      for(int j = fmin(dots[i][1],dots[i-1][1]); j < fmax(dots[i][1], dots[i-1][1]); j++)
      {
        hori.at(dots[i][0]).at(j) = true;
      }
    }
    else
    {
      for(int j = fmin(dots[i][0],dots[i-1][0]); j < fmax(dots[i][0], dots[i-1][0]); j++)
      {
        vert.at(j).at(dots[i][1]) = true;
      }
    }
  }
  for(int i = 0; i < x; i++)
  {
    for(int j = 0; j < y; j++)
    {
      char cur;
      if(dotCoords.at(i).at(j))
      {
        int c = dotCoords.at(i).at(j);
        if(c >= 1 && c <= 10) cur = (char)((c-1) +'0');
        else if(c >= 11 && c <= 36) cur = (char)((c-11) + 'a');
        else cur = (char)(c-37+'A');
      }
      else if(hori.at(i).at(j) && vert.at(i).at(j))
      {
        cur = '+';
      }
      else if(hori.at(i).at(j))
      {
        cur = '-';
      }
      else if(vert.at(i).at(j))
      {
        cur = '|';
      }
      else
      {
        cur = '.';
      }
      cout << cur;
    }
    cout << endl;
  }
}