#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int q; scanf("%d", &q);
  while(q--)
  {
    int n; scanf("%d", &n);
    int sum = 0;
    vector<int> vals;
    while(n--)
    {
      int add; scanf("%d", &add);
      sum += add;
      vals.push_back(add);
    }
    double avg = (double) sum / vals.size();

    int above = 0;
    for(int val : vals)
    {
      if(val > avg) above++;
    }

    printf("%.3f%%\n", above*100.0/vals.size());
  }
}