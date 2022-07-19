#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

int main()
{
  string des;
  getline(cin, des);
  int flagCount; scanf("%d\n", &flagCount);
  vector<vector<string>> flags(flagCount);
  
  int a = 0;
  while(flagCount--)
  {
    string flag; getline(cin, flag);
    stringstream f(flag);
    int j = 0;
    string token;
    while(getline(f, token, ','))
    {
      flags.at(a).push_back(token);
      j++;
    }
    a++;
  }

  vector<int> incongruities(flags.size(), 0);

  for(int i = 0; i < flags.size(); i++)
  {
    for(int j = 0; j < flags.size(); j++)
    {
      int incon = 0;
      if(i != j)
      {
        for(int k = 0; k < flags.at(i).size(); k++)
        {
          if(flags.at(i).at(k) != flags.at(j).at(k))
          {
            incon++;
          }
        }
      }
      incongruities[i] = fmax(incongruities.at(i), incon);
    }
  }

  int minIncon = (1E9)+1;
  vector<int> mins;
  for(int i = 0; i < flags.size(); i++)
  {
    if(incongruities[i] < minIncon)
    {
      mins.clear();
      mins.push_back(i);
      minIncon = incongruities[i];
    }
    else if(incongruities[i] == minIncon)
    {
      mins.push_back(i);
    }
  }
  
  for(int a : mins)
  {
    string output = "";
    for(int i = 0; i < flags.at(a).size(); i++)
    {
      output.append(flags.at(a).at(i));
      if(i != flags.at(a).size()-1) output.append(",");
    }
    cout << output << endl;
  }
}