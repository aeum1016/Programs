#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<int> rankUpStars = {-1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};

  int rank = 25; // Can't go below 20;
  int rStars = 0; // lose one for loss from 20+;
  int winStreak = 0; // bonuses on 6-25
  // max + 1 = new rank + 1;
  // 0 - 1 = lower rank max - 1

  string record; cin >> record;
  for(char c : record)
  {
    if(c == 'W') 
    {
      winStreak++;
      rStars++;
      if(rank >= 6 && winStreak >= 3) rStars++;
      if(rStars > rankUpStars.at(rank))
      {
        if(rank != 0) 
        {
          rStars = rStars - rankUpStars.at(rank);
          rank--;
        }
      }
    }
    else 
    {
      winStreak = 0;
      if(rank <= 20)
      {
        if(rank != 20 || rStars != 0) 
        {
          if(rank != 0) rStars--;
        }
      }
      if(rStars < 0)
      {
        rank++;
        rStars = rankUpStars.at(rank) - 1;
      }
    }
  }
  cout << (rank == 0 ? "Legend" : to_string(rank)); 
}