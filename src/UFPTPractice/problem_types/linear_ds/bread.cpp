#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int mergeSort(vector<pair<int, int>>& breads)
{
  if(breads.size() > 1)
  {
    vector<pair<int, int>> left(breads.begin(), breads.begin() + breads.size()/2);
    vector<pair<int, int>> right(breads.begin() + breads.size()/2, breads.end());
    int swaps = mergeSort(left);
    swaps += mergeSort(right);
    int Lptr = 0, Rptr = 0;
    for(int i = 0; i < breads.size(); i++)
    {
      if(Lptr == left.size())
      {
        breads[i] = right.at(Rptr);
        Rptr++;
      }
      else if(Rptr == right.size())
      {
        breads[i] = left.at(Lptr);
        Lptr++;
      }
      else if(left.at(Lptr).second < right.at(Rptr).second)
      {
        breads[i] = left.at(Lptr);
        Lptr++;
      }
      else
      {
        breads[i] = right.at(Rptr);
        Rptr++;
        swaps += left.size() - Lptr;
      }
    }
    return swaps;
  }
  else return 0;
}


int main()
{
  int q; scanf("%d\n", &q);
  vector<pair<int, int>> breads;
  int j = 0;
  while(j < q)
  {
    int a; scanf("%d", &a);
    breads.push_back(make_pair(a, 0));
    j++;
  }
  unordered_map<int, int> required;
  j = 0;
  while(j < q)
  {
    int a; scanf("%d", &a);
    required.emplace(a, j);
    j++;
  }
  for(int i = 0; i < breads.size(); i++)
  {
    breads[i].second = required.at(breads[i].first);
  }

  cout << (mergeSort(breads) % 2 ? "Impossible" : "Possible");
}