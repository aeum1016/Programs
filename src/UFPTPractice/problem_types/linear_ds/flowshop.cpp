#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  int swa, stages; scanf("%d %d\n", &swa, &stages);

  vector<vector<int>> times(swa, vector<int>(stages, 0));

  for(int i = 0; i < swa; i++)
  {
    for(int j = 0; j < stages; j++)
    {
      // time is max of the current input + 1 above or 1 back;
      int t; scanf("%d", &t);
      int tAbove = -1, tBack = -1;
      if(i - 1 >= 0) tAbove = times.at(i-1).at(j);
      if(j-1 >= 0) tBack = times.at(i).at(j-1);
      int max = fmax(tAbove, tBack);
      if(max == -1) max = 0;
      t += max;
      times[i][j] = t;
    }
  }
  for(int i = 0; i < swa; i++)
  {
    cout << times.at(i).at(stages-1) << " ";
  }
}