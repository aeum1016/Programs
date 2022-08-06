#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // 1 - add a vertex
  // 2 x y, new edge from x to y
  // 3 x, delete all in and out edges of x
  // 4 x y, remove edge from x to y
  // 5, every out edge is an in edge
  // 6, every non edge is an edge

  int v, e, q; cin >> v >> e >> q;
  vector<vector<bool>> g(v, vector<bool>(v, 0));
  bool outEdges = true;
  bool edgeIsOne = true;

  int x, y;
  while(e--)
  {
    cin >> x >> y;
    g[x][y] = true;
  }
  while(q--)
  {
    cin >> x;
    switch(x) {
      case 1: 
        g.push_back(vector<bool>(g.size()+1, !(edgeIsOne)));
        for(int i = 0; i < g.size()-1; i++)
        {
          g[i].push_back(!edgeIsOne);
        }
        break;
      case 2:
        cin >> x >> y;
        if(outEdges) {
          g[x][y] = edgeIsOne;
        }
        else {
          g[y][x] = edgeIsOne;
        }
        break;
      case 3:
        cin >> x;
        for(int i = 0; i < g.size(); i++)
        {
          if(i == x) g[i].assign(g.size(), !(edgeIsOne));
          else g[i][x] = !edgeIsOne;
        }
        break;
      case 4:
        cin >> x >> y;
        if(outEdges) g[x][y] = !edgeIsOne;
        else g[y][x] = !edgeIsOne;
        break;
      case 5:
        outEdges = !outEdges;
        break;
      case 6:
        edgeIsOne = !edgeIsOne;
        break;
    }
  }
  cout << g.size() << endl;
  int count = 0;
  for(int i = 0; i < g.size(); i++)
  {
    count = 0;
    long long hash = 0, multiplier = 1;
    for(int j = 0; j < g.size(); j++)
    {
      if(i == j) continue;
      if(outEdges)
      {
        if(g[i][j] == edgeIsOne) {
          count++;
          hash += multiplier*j;
          hash %= (long long) ((1E9)+7);
          multiplier *= 7;
          multiplier %= (long long) ((1E9)+7);
        }
      }
      else
      {
        if(g[j][i] == edgeIsOne) {
          count++;
          hash += multiplier*j;
          hash %= (long long) ((1E9)+7);
          multiplier *= 7;
          multiplier %= (long long) ((1E9)+7);
        }
      }
    }
    cout << count << ' ' << hash << endl;
  }
  return 0;
}