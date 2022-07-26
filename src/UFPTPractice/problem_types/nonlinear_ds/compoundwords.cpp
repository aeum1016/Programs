#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line;

  vector<string> words;

  while(getline(cin, line))
  {
    stringstream ss(line);
    string word;
    while(getline(ss, word, ' '))
    {
      words.push_back(word);
    }
  }

  set<string> concat;

  for(int i = 0; i < words.size(); i++)
  {
    for(int j = 0; j < words.size(); j++)
    {
      if(i != j)
      {
        concat.insert(words[i]+words[j]);
      }
    }
  }
  for(auto it = concat.begin(); it != concat.end(); it++)
  {
    cout << *it << endl;
  }
  return 0;
}