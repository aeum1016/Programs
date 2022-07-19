#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int s, q; scanf("%d %d\n", &s, &q);
  if(q == 1)
  {
    unordered_set<int> seen;
    while(s--)
    {
      int d; scanf("%d", &d);
      if(seen.find(7777-d) != seen.end())
      {
        cout << "Yes";
        return 0;
      }
      else
      {
        seen.insert(d);
      }
    }
    cout << "No";
    return 0;
  }
  else if(q == 2)
  {
    unordered_set<int> seen;
    int i = 0;
    while(i < s)
    {
      int d; scanf("%d", &d);
      seen.insert(d);
      i++;
    }
    if(seen.size() == s)
    {
      cout << "Unique";
      return 0;
    }
    else 
    {
      cout << "Contains duplicate";
      return 0;
    }
  }
  else if(q == 3)
  {
    unordered_map<int, int> counts;
    int i = 0;
    while(i < s)
    {
      int d; scanf("%d", &d);
      if(counts.find(d) == counts.end())
      {
        counts.emplace(d, 1);
      }
      else
      {
        if((++counts[d]) * 2 > s)
        {
          cout << d;
          return 0;
        }
      }
      i++;
    }
    cout << -1;
    return 0;
  }
  else if(q == 4)
  {
    vector<int> nums;
    while(s--)
    {
      int d; scanf("%d", &d);
      nums.push_back(d);
    }
    sort(nums.begin(), nums.end());
    if(nums.size() % 2)
    {
      cout << nums.at(nums.size()/2);
      return 0;
    }
    else
    {
      cout << nums.at((nums.size()/2)-1) << " " << nums.at(nums.size()/2);
      return 0;
    }
  }
  else
  {
    vector<int> nums;
    while(s--)
    {
      int d; scanf("%d", &d);
      nums.push_back(d);
    }
    sort(nums.begin(), nums.end());
    for(int i : nums)
    {
      if(i >= 100 && i <= 999)
      {
        cout << i << " ";
      }
    }
    return 0;
  }
}