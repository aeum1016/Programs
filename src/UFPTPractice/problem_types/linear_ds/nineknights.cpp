#include <bits/stdc++.h>

using namespace std;

int main()
{
  int kCount = 0;
  vector<vector<bool>> knights(5, vector<bool>(5, false));
  vector<vector<int>> moves({{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}});
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      char c; scanf("%c", &c);
      if(c == 'k')
      {
        kCount++;
        knights[i][j] = true;
        for(vector<int> move : moves)
        {
          if(i + move[0] < 0 || i + move[0] >= 5 || j + move[1] < 0 || j + move[1] >= 5) continue;
          else if(knights.at(i+move[0]).at(j+move[1]))
          {
            cout << "invalid";
            return 0;
          }
        }
      }
    }
    char t; scanf("%c", &t);
  }
  cout << (kCount == 9 ? "valid" : "invalid");
  return 0;
}