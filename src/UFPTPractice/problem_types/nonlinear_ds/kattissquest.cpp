#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<long long, priority_queue<long long>> quests;
  quests[INT_MAX].push(0);
  long long q; cin >> q;
  while(q--)
  {
    string s; cin >> s;
    if(s == "add")
    {
      long long e, g; cin >> e >> g;
      quests[e].push(g);
    }
    else
    {
      long long e; cin >> e;
      long long g = 0;
      while(true)
      {
        auto it = quests.lower_bound(e);
        if(it->first > e) it--;
        if(quests.begin()->first > e) break;

        e-=it->first;
        g+=it->second.top();
        quests[it->first].pop();

        if(it->second.size() == 0) 
        {
          quests.erase(it);
        }

      }
      cout << g << endl;
    }
  }
  return 0;
}