#include <bits/stdc++.h>
using namespace std;

void printString(vector<string>& a, vector<vector<int>>& b, int current)
{
  cout << a[current];
  for(int i : b.at(current))
  {
    printString(a, b, i);
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    vector<string> a(q);
    vector<vector<int>> b(q, vector<int>());
    int i = 0;
    while(i < q)
    {
      string s; cin >> s;
      a[i] = s;
      i++;
    }
    i = 0;
    int c = 1, d;
    while(i < q-1)
    {
      cin >> c >> d;
      b[c-1].push_back(d-1);
      i++;
    }

    printString(a, b, c-1);

    return 0;
}