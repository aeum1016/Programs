#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, p, l; cin >> n >> p >> l;

  unordered_map<string, int> people;

  while(n--)
  {
    string a; cin >> a;
    people.emplace(a, 0);
  }
  bool winner = false;
  while(l--)
  {
    string a; 
    int pts;
    cin >> a >> pts;
    if(people.find(a) != people.end())
    {
      people[a]+=pts;
      if(people[a] >= p)
      {
        cout << a << " wins!" << endl;
        people.erase(a);
        winner = true;
      }
    }
  }
  if(!winner) cout << "No winner!";
  return 0;
}