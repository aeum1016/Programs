#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, int> catToNum;
  unordered_map<int, string> numToCat;
  vector<set<int>> infectionLevels(101, set<int>()); 
  unordered_map<int, int> numToLevel;

  int q; cin >> q;
  while(q--)
  {
    int a; cin >> a;
    if(a == 0)
    {
      //insert
      string n;
      int p;
      cin >> n >> p;
      infectionLevels[p].emplace(catToNum.size());
      numToLevel.emplace(catToNum.size(), p);
      numToCat.emplace(catToNum.size(), n);
      catToNum.emplace(n, catToNum.size());
    }
    else if(a == 1)
    {
      //update
      string n;
      int p;
      cin >> n >> p;
      if(catToNum.find(n) != catToNum.end())
      {
        int num = catToNum.at(n);
        infectionLevels[numToLevel.at(num)].erase(num);
        numToLevel[num]+=p;
        infectionLevels[numToLevel.at(num)].emplace(num);
      }
    }
    else if(a == 2)
    {
      //treat
      string n; cin >> n;
      if(catToNum.find(n) != catToNum.end())
      {
        int num = catToNum.at(n);
        infectionLevels[numToLevel.at(num)].erase(num);
        numToLevel.erase(num);
        numToCat.erase(num);
      }
    }
    else
    {
      //top priority
      bool notEmpty = false;
      for(int i = 100; i >= 30; i--)
      {
        if(!infectionLevels.at(i).empty())
        {
          if(numToCat.find(*(infectionLevels.at(i).begin())) != numToCat.end())
          {
            cout << numToCat.at(*(infectionLevels.at(i).begin())) << endl;
            notEmpty = true;
            break;
          }
        }
      }
      if(!notEmpty) cout << "The clinic is empty" << endl;
    }
  }

  return 0;

}