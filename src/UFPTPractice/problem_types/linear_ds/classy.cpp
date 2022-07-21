#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const pair<string, long long> a, const pair<string, long long> b)
{
  if(a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

int main()
{
  int q; scanf("%d\n", &q);
  while(q--)
  {
    int n; scanf("%d\n", &n);
    vector<pair<string, long long>> people(n);
    while(n--)
    {
      string name; cin >> name;
      name = name.substr(0, name.size()-1);
      string nClass; cin >> nClass;
      string t; cin >> t;
      stringstream classSS(nClass);
      vector<int> a;
      while(getline(classSS, t, '-'))
      {
        long long b;
        if(t == "upper") a.push_back(1);
        else if(t == "middle") a.push_back(0);
        else a.push_back(-1);
      }
      int j = 9;
      long long rank = 0;
      for(int i = a.size()-1; i >= 0; i--)
      {
        rank += a.at(i) * pow(10, j);
        j--;
      }
      people[n] = make_pair(name, rank);
    }
    stable_sort(people.begin(), people.end(), cmp);

    for(pair<string, long long> a : people)
    {
      cout << a.first << endl;
    }
    cout << "==============================" << endl;
  }
}