#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  int q; scanf("%d", &q);
  while(q--)
  {
    int num; scanf("%d", &num);
    vector<int> line;
    int movements = 0;
    for(int i = 0; i < 20; i++)
    {
      int h; scanf("%d", &h);
      if(line.empty()) line.push_back(h);
      else
      {
        for(int j = 0; j < line.size(); j++)
        {
          if(line.at(j) > h)
          {
            movements += line.size()-j;
            line.push_back(h);
            break;
          }
        }
        if(line.size() == i) line.push_back(h);
        else sort(line.begin(), line.end());
      }
    }
    cout << num << " " << movements << endl;
  }
}