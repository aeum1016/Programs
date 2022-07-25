#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  unordered_map<string, vector<int>> trips;

  while(n--)
  {
    string c;
    int y;
    cin >> c >> y;
    if(trips.find(c) == trips.end())
    {
      vector<int> a({y});
      trips.emplace(c, a);
    }
    else
    {
      trips[c].push_back(y);
    }
  }
  for(auto it = trips.begin(); it != trips.end(); it++)
  {
    sort(it->second.begin(), it->second.end());
  }
  cin >> n;
  while(n--)
  {
    string c;
    int k;
    cin >> c >> k;
    cout << trips[c][k-1] << endl;
  }

  return 0;
}