#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  priority_queue<int, vector<int>, greater<int>> notInTree;
  vector<int> counts(n+2, 0);
  vector<int> qu(n+3);

  int i = 0;
  while(i < n)
  {
    int q; cin >> q;
    qu[i+1] = q;
    counts[q]++;
    i++;
  }
  for(int j = 1; j <= n+2; j++) {
    if(counts[j] == 0) notInTree.emplace(j);
  }

  int m = 0;
  
  for(int j = 0; j < n; j++) {
    qu[j] = notInTree.top();
    m = max(qu[j], m);
    notInTree.pop();
    if(--counts[qu[j+1]] == 0) notInTree.emplace(qu[j+1]);
  }
  if(m > notInTree.top()) cout << "Error";
  else 
  {
    for(int j = 0; j < n; j++)
    {
      cout << qu[j] << endl;
    }
  }

  return 0;

}