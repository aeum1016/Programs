#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);
  while(q--)
  {
    string line;
    string product;
    getline(cin, line);
    int square = sqrt(line.size());
    for(int i = 0; i < square; i++)
    {
      for(int j = 1; j <= square; j++)
      {
        product = line.at(line.size()-(j*square)+i) + product;
      }
    }
    cout << product << endl;
  }
}