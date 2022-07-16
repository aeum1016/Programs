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

  while(q--)
  {
    int time;
    scanf("%d", &time);

    if(orders.front() <= time - 1000)
    {
      orders.pop();
      orders.push(time);
    }
    else
    {
      orders.push(time);
    }
  }
  printf("%d", (orders.size()+1)/2);
  return 0;
}