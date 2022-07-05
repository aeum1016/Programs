#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int n, k;
  while(scanf("%d %d\n", &n, &k) != EOF)
  {
    vector<int> wins(n, 0);
    vector<int> losses(n, 0);

    for(int i = 0; i < k*n*(n-1)/2; i++)
    {
      int p1, p2;
      string m1, m2;
      cin >> p1 >> m1 >> p2 >> m2;
      p1--;
      p2--;
      if(!m1.compare("rock"))
      {
        if(!m2.compare("scissors"))
        {
          wins[p1]++;
          losses[p2]++;
        }
        else if(!m2.compare("paper"))
        {
          losses[p1]++;
          wins[p2]++;
        }
      }
      else if(!m1.compare("scissors"))
      {
        if(!m2.compare("paper"))
        {
          wins[p1]++;
          losses[p2]++;
        }
        else if(!m2.compare("rock"))
        {
          losses[p1]++;
          wins[p2]++;
        }
      }
      else
      {
        if(!m2.compare("rock"))
        {
          wins[p1]++;
          losses[p2]++;
        }
        else if(!m2.compare("scissors"))
        {
          losses[p1]++;
          wins[p2]++;
        }
      }
    }
    for(int i = 0; i < n; i++)
    {
      if(wins.at(i) + losses.at(i) != 0) printf("%0.3f\n", wins.at(i) / (double)(wins.at(i)+losses.at(i)));
      else printf("-\n");
    }
    printf("\n");
  }
}