#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, m, total, cost;
set<ll> bst;
ll dist[300002] = {0};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  total = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> m;
    bst.insert(m);
    cost = 0;
    auto cur = bst.find(m);
    if(i != 0)
    {
      if(cur != bst.begin())
      {
        auto prev = cur;
        prev--;
        cost = max(dist[*(prev)]+1, cost);
      }
      if(cur != bst.end())
      {
        auto next = cur;
        next++;
        if(next != bst.end())
        {
          cost = max(dist[*(next)]+1, cost);
        }
      }
    }

    total += cost;
    dist[m] = cost;
    cout << total << endl;
  }
  
  return 0;
}