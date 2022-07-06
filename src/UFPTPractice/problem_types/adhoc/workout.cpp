#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  vector<vector<int>> myUsage(10, vector<int>());
  for(int i = 0; i < 10; i++)
  {
    int use, rest; scanf("%d %d", &use, &rest);
    myUsage.at(i).push_back(use);
    myUsage.at(i).push_back(rest);
  }
  vector<vector<int>> oUsage(10, vector<int>());
  for(int i = 0; i < 10; i++)
  {
    int use, rest, start; scanf("%d %d %d", &use, &rest, &start);
    oUsage.at(i).push_back(use);
    oUsage.at(i).push_back(rest);
    oUsage.at(i).push_back(start);
    oUsage.at(i).push_back(0);
  }

  int curMachine = 0;
  int curTime = 0;
  // one run through, update start time for each machine after use
  for(int j = 0; j < 3; j++)
  {
    for(int i = 0; i < 10; i++)
    {
      //machine i
      //check if machine is open
      //wait until it is open
      //update time to after rest
      //update start time for user

      int lastUse = oUsage.at(i).at(2) + oUsage.at(i).at(0) + ((curTime-oUsage.at(i).at(2)) / (oUsage.at(i).at(0)+oUsage.at(i).at(1))) * (oUsage.at(i).at(0)+oUsage.at(i).at(1));
      //machine opens at t and then between t + use and t + use + rest
      if(curTime > lastUse)
      {
        curTime += myUsage.at(i).at(0);
        oUsage.at(i).at(2) = fmax(curTime, lastUse+oUsage.at(i).at(1));
        curTime += myUsage.at(i).at(1);
      }
      else if(curTime < oUsage.at(i).at(2))
      {
        curTime += myUsage.at(i).at(0);
        oUsage.at(i).at(2) = fmax(curTime, oUsage.at(i).at(2));
        curTime += myUsage.at(i).at(1);
      }
      else {
        curTime += (lastUse - curTime) + myUsage.at(i).at(0);
        oUsage.at(i).at(2) = fmax(curTime, lastUse+oUsage.at(i).at(1));
        curTime += myUsage.at(i).at(1);
      }
    }
  }
  curTime -= myUsage.at(9).at(1);
  printf("%d", curTime);
  return 0;
}