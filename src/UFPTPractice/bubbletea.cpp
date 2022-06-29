#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int teaTypes; scanf("%d", &teaTypes);
  vector<int> teaCosts;

  for(int i = 0; i < teaTypes; i++)
  {
    int tCost;
    scanf("%d", &tCost);
    teaCosts.push_back(tCost);
  }

  int toppingTypes; scanf("%d", &toppingTypes);
  vector<int> toppingCosts;

  for(int i = 0; i < toppingTypes; i++)
  {
    int cost;
    scanf("%d", &cost);
    toppingCosts.push_back(cost);
  }

  long long minCost = 10E9+1;

  for(int i = 0; i < teaTypes; i++)
  {
    int q; scanf("%d", &q);
    while(q--)
    {
      int combo; scanf("%d", &combo);
      if(teaCosts.at(i) + toppingCosts.at(combo-1) < minCost) minCost = teaCosts.at(i) + toppingCosts.at(combo-1);
    }
  }
  int money; scanf("%d", &money);
  printf("%d", ((money / minCost)-1) < 0 ? 0 : (money/minCost) - 1);

  return 0;
}