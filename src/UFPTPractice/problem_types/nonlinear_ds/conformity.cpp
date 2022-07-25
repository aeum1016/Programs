#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<vector<int>, int> p;

  int q; cin >> q;
  int max = 0;
  int nMaxes = 0;
  while(q--)
  {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    vector<int> courses({a, b, c, d, e});
    sort(courses.begin(), courses.end());

    if(p.find(courses) != p.end())
    {
      int nMax = ++p[courses];
      if(nMax > max)
      {
        max = nMax;
        nMaxes = nMax;
      }
      else if(nMax == max)
      {
        nMaxes+=nMax;
      }
    }
    else
    {
      p.emplace(courses, 1);
      if(1 > max)
      {
        max = 1;
        nMaxes = 1;
      }
      else if(1 == max)
      {
        nMaxes++;
      }
    }
  }
  cout << nMaxes;
  return 0;
}