#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool cmp(const string a, const string b)
{
  string aLower, bLower;
  for(char c : a)
  {
    aLower += (char)tolower(c);
  }
  for(char c : b)
  {
    bLower += (char)tolower(c);
  }
  return aLower < bLower;
}

int main()
{
  int l, q;
  while(scanf("%d %d\n", &l, &q) != EOF)
  {
    if(!l && !q) return 0;
    vector<string> strings(q, "");
    for(int i = 0; i < l; i++)
    {
      for(int j = 0; j < q; j++)
      {
        char c; scanf("%c", &c);
        strings.at(j)+=c;
      }
      char t; scanf("%c", &t);
    }
    stable_sort(strings.begin(), strings.end(), cmp);

    for(int i = 0; i < l; i++)
    {
      for(int j = 0; j < q; j++)
      {
        cout << strings.at(j).at(i);
      }
      cout << endl;
    }
    cout << endl;
  }
}