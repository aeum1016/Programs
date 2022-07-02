#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int q; scanf("%d", &q);

  while(q--)
  {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<int>> reqs;
    vector<int> value;
    for(int i = 0; i < n; i++)
    {
      int req; scanf("%d", &req);
      reqs.push_back(vector<int>());
      while(req--)
      {
        int requirement; scanf("%d", &requirement);
        reqs[i].push_back(requirement);
      }
      int val; scanf("%d", &val);
      value.push_back(val);
    }

    vector<int> tickets(m, 0);

    for(int i = 0; i < m; i++)
    {
      int count; scanf("%d", &count);
      tickets[i] = count;
    }

    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
      bool ableToBuy = true;
      while(ableToBuy)
      {
        for(int requirement : reqs.at(i))
        {
          if(tickets[requirement-1] > 0) tickets[requirement-1]--;
          else
          {
            ableToBuy = false;
          }
        }
        if(ableToBuy) sum+=value[i];
      }
    }
    printf("%d\n", sum);
  }
}