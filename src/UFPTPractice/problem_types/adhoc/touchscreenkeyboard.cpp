#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  vector<vector<char>> keyboard;
  keyboard.push_back(vector<char>({'q','w','e','r','t','y','u','i','o','p'}));
  keyboard.push_back(vector<char>({'a','s','d','f','g','h','j','k','l'}));
  keyboard.push_back(vector<char>({'z','x','c','v','b','n','m'}));

  int q; scanf("%d", &q);
  while(q--)
  {
    string base;
    int cmps;
    cin >> base >> cmps;
    map<int, vector<string>> comparisons;
    while(cmps--)
    {
      string cmp;
      cin >> cmp;
      int totDist = 0;
      for(int i = 0; i < base.length(); i++)
      {
        int x1, y1, x2, y2;
        for(int j = 0; j < keyboard.size(); j++)
        {
          for(int k = 0; k < keyboard.at(j).size(); k++)
          {
            if(base.at(i) == keyboard.at(j).at(k))
            {
              x1 = j;
              y1 = k;
            }
            if(cmp.at(i) == keyboard.at(j).at(k))
            {
              x2 = j;
              y2 = k;
            }
          }
        }
        totDist += abs(x1-x2) + abs(y1-y2);
      }
      if(comparisons.find(totDist) != comparisons.end())
      {
        comparisons[totDist].push_back(cmp);
      }
      else 
      {
        
        comparisons.emplace(totDist, vector<string>({cmp}));
      }
    }

    for(auto it = comparisons.begin(); it != comparisons.end(); it++)
    {
      sort(it->second.begin(), it->second.end());
      for(string word : it->second)
      {
        cout << word << ' ' << it->first << endl;
      }
    }
  }
}