#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
  int q, s;
  scanf("%d %d", &q, &s);

  // start with one server, vector of times of start
  queue<int> orders;
  int maxServers = 0;

  while(q--)
  {
    int time;
    scanf("%d", &time);

    while(orders.size() && orders.front() <= time - 1000)
    {
      orders.pop();
    }
    orders.push(time);
    maxServers = fmax(maxServers, ceil(((double)orders.size())/s));
  }
  printf("%d", maxServers);
  return 0;
}