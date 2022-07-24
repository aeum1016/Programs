#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  bool days[365];
  fill(days, days+365, 0);
  while(q--)
  {
    int s, e; cin >> s >> e;
    for(int i = s; i <= e; i++)
    {
      days[i-1] = true;
    }
  }
  int d = 0;
  for(int i = 0; i < 365; i++)
  {
    if(days[i]) d++;
  }
  cout << d;
  return 0;
}