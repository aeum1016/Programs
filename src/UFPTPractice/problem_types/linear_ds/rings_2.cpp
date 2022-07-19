#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int r, c; scanf("%d %d\n", &r, &c);
  vector<vector<int>> rings(r, vector<int>(c, 0));
  vector<vector<bool>> checked(r, vector<bool>(c, false));

  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      char c; scanf("%c", &c);
      if(c == '.') checked.at(i)[j] = true;
    }
    char t; scanf("%c", &t);
  }

  int ring = 1;
  bool allChecked = false;
  while(!allChecked)
  {
    vector<vector<int>> newRing;
    for(int i = 0; i < r; i++)
    {
      for(int j = 0; j < c; j++)
      {
        if(!checked.at(i).at(j))
        {
          if(i - 1 < 0 || i + 1 >= r || j - 1 < 0 || j + 1 >= c) newRing.push_back(vector<int>({i, j}));
          else if(i - 1 >= 0 && checked.at(i-1).at(j))
          {
            newRing.push_back(vector<int>({i, j}));
          }
          else if(i + 1 < r && checked.at(i+1).at(j))
          {
            newRing.push_back(vector<int>({i, j}));
          }
          else if(j - 1 >= 0 && checked.at(i).at(j-1))
          {
            newRing.push_back(vector<int>({i, j}));
          }
          else if(j + 1 < c && checked.at(i).at(j+1))
          {
            newRing.push_back(vector<int>({i, j}));
          }
        }
      }
    }
    if(newRing.size() == 0) allChecked = true;
    for(vector<int> nr : newRing)
    {
      rings.at(nr[0]).at(nr[1]) = ring;
      checked.at(nr[0]).at(nr[1]) = true;
    }
    ring++;
  }

  cout << setfill('.');
  for(int i = 0; i < rings.size(); i++)
  {
    for(int j = 0; j < rings.at(i).size(); j++)
    {
      string s = (rings.at(i).at(j) == 0 ? "." : to_string(rings.at(i).at(j)));
      cout << setw(ring >= 10 ? 3 : 2) << s;
    }
    cout << endl;
  }
}