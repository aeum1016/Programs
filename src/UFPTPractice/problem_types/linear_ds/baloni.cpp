#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int q;
  scanf("%d", &q);
  vector<int> heights((1E6)+2, 0);

  int darts = 0;

  while(q--)
  {
    int a;
    scanf("%d", &a);

    if(heights[a+1] > 0)
    {
      heights[a+1]--;
    }
    else
    {
      darts++;
    }
    heights[a]++;
  }
  printf("%d", darts);
  return 0;
}