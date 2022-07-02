#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  vector<vector<int>> spots(4);

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      int val; scanf("%d", &val);
      spots[i].push_back(val);
    }
  }

  int move; scanf("%d", &move);

  if(move == 0)
  {
    for(int i = 0; i < 4; i++)
    {
      int spot = 0;
      for(int j = 0; j < 4;)
      {
        while(j < 3 && spots.at(i).at(j) == 0) j++;
        int val = spots.at(i).at(j);
        j++;
        while(j < 4 && spots.at(i).at(j) == 0) j++;
        if(j < 4 && spots.at(i).at(j) == val)
        {
          val*=2;
          j++;
        }
        spots[i][spot] = val;
        spot++;
      }
      for(int j = spot; j<4; j++)
      {
        spots[i][j] = 0;
      }
    }
  }
  else if(move == 2)
  {
    for(int i = 0; i < 4; i++)
    {
      int spot = 3;
      for(int j = 3; j >= 0;)
      {
        while(j > 0 && spots.at(i).at(j) == 0) j--;
        int val = spots.at(i).at(j);
        j--;
        while(j >= 0 && spots.at(i).at(j) == 0) j--;
        if(j >= 0 && spots.at(i).at(j) == val)
        {
          val*=2;
          j--;
        }
        spots[i][spot] = val;
        spot--;
      }
      for(int j = spot; j>=0; j--)
      {
        spots[i][j] = 0;
      }
    }
  }

  if(move == 1)
  {
    for(int i = 0; i < 4; i++)
    {
      int spot = 0;
      for(int j = 0; j < 4;)
      {
        while(j < 3 && spots.at(j).at(i) == 0) j++;
        int val = spots.at(j).at(i);
        j++;
        while(j < 4 && spots.at(j).at(i) == 0) j++;
        if(j < 4 && spots.at(j).at(i) == val)
        {
          val*=2;
          j++;
        }
        spots[spot][i] = val;
        spot++;
      }
      for(int j = spot; j<4; j++)
      {
        spots[j][i] = 0;
      }
    }
  }
  else if(move == 3)
  {
    for(int i = 0; i < 4; i++)
    {
      int spot = 3;
      for(int j = 3; j >= 0;)
      {
        while(j > 0 && spots.at(j).at(i) == 0) j--;
        int val = spots.at(j).at(i);
        j--;
        while(j >= 0 && spots.at(j).at(i) == 0) j--;
        if(j >= 0 && spots.at(j).at(i) == val)
        {
          val*=2;
          j--;
        }
        spots[spot][i] = val;
        spot--;
      }
      for(int j = spot; j>=0; j--)
      {
        spots[j][i] = 0;
      }
    }
  }

  for(vector<int> rows : spots)
  {
    for(int spot : rows)
    {
      printf("%d ", spot);
    }
    printf("\n");
  }

  return 0;
}