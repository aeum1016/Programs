#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n; cin >> n;
  int i = 0;
  unordered_map<int, int> last;
  int min = n;
  while(i < n)
  {
    int q; cin >> q;
    if(last.find(q) != last.end())
    {
      min = fmin(min, i - last[q]);
      last[q] = i;
    }
    else
    {
      last.emplace(q, i);
    }
    i++;
  }
  cout << min;
  return 0;
}