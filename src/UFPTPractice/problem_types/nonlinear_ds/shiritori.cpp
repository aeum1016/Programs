#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  int i = 0;
  string last = "";
  unordered_set<string> used;
  while(i < q)
  {
    string a; cin >> a;
    if(last == "")
    {
      last = a;
    }
    else
    {
      if(last.at(last.size()-1) != a.at(0) || used.find(a) != used.end())
      {
        cout << "Player " << (i%2)+1 << " lost";
        return 0;
      }
      else
      {
        last = a;
      }
    }
    used.emplace(a);
    i++;
  }
  cout << "Fair Game";
  return 0;
}