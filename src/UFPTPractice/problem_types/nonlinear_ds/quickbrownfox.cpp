#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  string a;
  getline(cin, a);

  set<char> cs;
  vector<char> notFound;
  while(q--)
  {
    cs.clear();
    notFound.clear();
    string s; getline(cin, s);
    for(char c : s)
    {
      cs.emplace(tolower(c));
    }
    for(int i = 0; i < 26; i++)
    {
      if(cs.find('a'+i) == cs.end())
      {
        notFound.push_back('a'+i);
      }
    }
    if(notFound.empty())
    {
      cout << "pangram" << endl;
    }
    else
    {
      cout << "missing ";
      for(char c : notFound)
      {
        cout << c;
      }
      cout << endl;
    }
  }
  return 0;
}