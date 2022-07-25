#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, string> a, const pair<int, string> b)
{
  if(a.first == b.first)
  {
    return a < b;
  }
  else
  {
    return a.first > b.first;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;

  unordered_map<string, unordered_set<string>> words;
  unordered_map<string, int> seen;

  while(q--)
  {
    string name; cin >> name;
    string line; getline(cin, line);

    if(words.find(name) == words.end())
    {
      words.emplace(name, unordered_set<string>());
    }
    
    string word;
    stringstream ss(line);
    while(getline(ss, word, ' '))
    {
      if(word == "") continue;
      if(seen.find(word) == seen.end())
      {
        seen.emplace(word, 1);
      }
      else
      {
        seen[word]++;
      }
      words[name].emplace(word);
    }
  }
  vector<pair<int, string>> a;
  for(auto it = seen.begin(); it != seen.end(); it++)
  {
    bool allSeen = true;
    for(auto it2 = words.begin(); it2 != words.end(); it2++)
    {
      if(it2->second.find(it->first) == it2->second.end()) allSeen = false;
    }
    if(allSeen)
    {
      a.push_back(make_pair(it->second, it->first));
    }
  }
  sort(a.begin(), a.end(), cmp);

  if(a.size() == 0)
  {
    cout << "ALL CLEAR";
  }
  for(pair<int, string> p : a)
  {
    cout << p.second << endl;
  }

  return 0;
}