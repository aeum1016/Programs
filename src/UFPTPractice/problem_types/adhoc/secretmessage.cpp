#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);
  while(q--)
  {
    string s;
    cin >> s;
    int rt = ceil(sqrt(s.size()));
    vector<vector<char>> mes(rt, vector<char>(rt, ' '));
    for(int i = 0; i < s.size(); i++)
    {
      int row = i / rt;
      int col = i % rt;
      mes.at(row).at(col) = s.at(i);
    }

    string message = "";

    for(int i = 0; i < rt; i++)
    {
      for(int j = rt-1; j >= 0; j--)
      {
        if(mes.at(j).at(i) != ' ')
        {
          message+=mes.at(j).at(i);
        }
      }
    }
    cout << message << endl;
  }
  return 0;
}