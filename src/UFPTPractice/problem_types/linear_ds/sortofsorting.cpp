#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool cmp(const string a, const string b)
{
  string aN = a.size() > 2 ? a.substr(0, 2) : a;
  string bN = b.size() > 2 ? b.substr(0, 2) : b;
  return aN < bN;
}

int main()
{
  int q;
  while(scanf("%d\n", &q) != EOF)
  {
    if(!q) return 0;
    vector<string> strings(q);

    for(int j = 0; j < q; j++)
    {
      string a; cin >> a;
      strings.at(j) = a;
    }

    stable_sort(strings.begin(), strings.end(), cmp);

    for(int j = 0; j < q; j++)
    {
      cout << strings.at(j) << endl;
    }
    cout << endl;
  }
}