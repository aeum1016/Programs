#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_set<int> jack;

  while(true)
  {
    jack.clear();
    int a, b; cin >> a >> b;
    if(!a && !b) return 0;
    while(a--)
    {
      int c; cin >> c;
      jack.emplace(c);
    }
    int d = 0;
    while(b--)
    {
      int c; cin >> c;
      if(jack.find(c) != jack.end()) d++;
    }
    cout << d << endl;
  }
  return 0;
}