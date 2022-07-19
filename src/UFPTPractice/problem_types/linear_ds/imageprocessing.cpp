#include <bits/stdc++.h>

using namespace std;

int main()
{
  int h, w, n, m; scanf("%d %d %d %d", &h, &w, &n, &m);
  vector<vector<int>> picture(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      int p; scanf("%d", &p);
      picture[i][j] = p;
    }
  }
  vector<vector<int>> kernel(n, vector<int>(m, 0));
  for(int i = n-1; i >= 0; i--)
  {
    for(int j = m-1; j >= 0; j--)
    {
      int p; scanf("%d", &p);
      kernel[i][j] = p;
    }
  }

  for(int i = 0; i < h-n+1; i++)
  {
    for(int j = 0; j < w-m+1; j++)
    {
      int sum = 0;
      for(int k = 0; k < n; k++)
      {
        for(int l = 0; l < m; l++)
        {
          sum += kernel.at(k).at(l) * picture.at(i+k).at(j+l);
        }
      }
      cout << sum << ' ';
    }
    cout << endl;
  }

}