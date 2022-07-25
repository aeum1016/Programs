#include <bits/stdc++.h>

using namespace std;

int main()
{
  int q; cin >> q;
  set<pair<int, int>> points;
  vector<vector<int>> apart({{2018, 0}, {0, 2018}, {-2018, 0}, {0, -2018}, 
                            {1680, 1118}, {1118, 1680}, {-1680, 1118}, {-1118, 1680},
                            {1680, -1118}, {1118, -1680}, {-1680, -1118}, {-1118, -1680}});
  int p = 0;
  while(q--)
  {
    int a, b; cin >> a >> b;
    points.emplace(make_pair(a, b));
    for(int i = 0; i < 12; i++)
    {
      if(points.find(make_pair(a+apart[i][0], b+apart[i][1])) != points.end()) 
      {
        p++;
      }
    }
  }
  cout << p;
}