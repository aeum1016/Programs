#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);

  vector<int> GIS;

  while(q--)
  {
    int a; scanf("%d", &a);
    if(!GIS.size())
    {
      GIS.push_back(a);
    }
    else
    {
      if(GIS.at(GIS.size()-1) < a)
      {
        GIS.push_back(a);
      }
    }
  }
  printf("%d\n", GIS.size());
  for(int a : GIS)
  {
    printf("%d ", a);
  }
  return 0;
}