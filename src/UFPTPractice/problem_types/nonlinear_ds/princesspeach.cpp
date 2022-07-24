#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, f; cin >> n >> f;

  vector<bool> found(n, false);
  for(int i = 0; i < f; i++)
  {
    int fn; cin >> fn;
    found.at(fn) = true;
  }
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    if(!found[i]) cout << i << endl;
    else count++;
  }
  cout << "Mario got " << count << " of the dangerous obstacles.";
  return 0;
}