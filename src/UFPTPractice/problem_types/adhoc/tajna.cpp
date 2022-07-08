#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  string s; cin >> s;
  int max = ceil(sqrt(s.size()));
  int rows = 0, cols = 0;
  for(int i = max; i >= 1; i--)
  {
    for(int j = i; j <= s.size(); j++)
    {
      if(i*j == s.size())
      {
        cols = i;
        rows = j;
        break;
      }
    }
    if(rows) break;
  }

  vector<vector<char>> m(rows, vector<char>(cols));
  for(int i = 0; i < s.size(); i++)
  {
    m.at(i/cols).at(i%cols) = s.at(i);
  }

  for(int i = 0; i < cols; i++)
  {
    for(int j = 0; j < rows; j++)
    {
      cout << m.at(j).at(i);
    }
  }
}
