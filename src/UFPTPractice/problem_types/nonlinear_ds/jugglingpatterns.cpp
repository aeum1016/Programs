#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a;
  vector<int> throwH;
  while(getline(cin, a))
  {
    int balls = 0;
    throwH.clear();
    for(char c : a)
    {
      throwH.push_back(c-'0');
      balls += c-'0';
    }

    if(balls%throwH.size())
    {
      cout << a << ": invalid # of balls\n";
      continue;
    }
    balls /= throwH.size();

    unordered_set<int> b;
    int i = 0;
    for(int c : throwH)
    {
      b.insert((c+i)%throwH.size());
      i++;
    }
    if(b.size() == throwH.size()) cout << a << ": valid with " << balls << " balls\n";
    else cout << a << ": invalid pattern\n";
  }
  return 0;
}