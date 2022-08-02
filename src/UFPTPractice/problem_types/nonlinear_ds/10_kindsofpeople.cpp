#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> m;
vector<vector<int>> islands;

vector<int> dX({1, -1, 0, 0});
vector<int> dY({0, 0, 1, -1});

bool valid(int x, int y)
{
  if(x < 0 || x >= m.size() || y < 0 || y >= m[0].size()) return false;
  return true;
}

void bfs(int x, int y, bool one, int island)
{
  islands[x][y] = island;
  for(int i = 0; i < 4; i++)
  {
    if(valid(x+dX[i], y+dY[i]))
    {
      if(m[x+dX[i]][y+dY[i]] == one && !islands[x+dX[i]][y+dY[i]]) bfs(x+dX[i], y+dY[i], one, island);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c; cin >> r >> c;

  m = vector<vector<bool>>(r, vector<bool>(c, false));
  islands = vector<vector<int>>(r, vector<int>(c, 0));

  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      char x; cin >> x;
      m[i][j] = x-48;
    }
  }

  int island = 1;
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      if(!islands[i][j])
      {
        bfs(i, j, m[i][j], island);
        island++;
      }
    }
  }

  int q; cin >> q;
  while(q--)
  {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(valid(x1-1, y1-1) && valid(x2-1, y2-1))
    {
      if(islands[x1-1][y1-1] == islands[x2-1][y2-1])
      {
        cout << (m[x1-1][y1-1] ? "decimal" : "binary") << endl;
      }
      else cout << "neither" << endl;
    }
    else cout << "neither" << endl;
  }
}