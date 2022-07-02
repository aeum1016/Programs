#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
  int smallest; scanf("%d", &smallest);
  vector<int> numPapers(smallest+1);
  int i = 2;
  while(i <= smallest)
  {
    int n; scanf("%d", &n);
    numPapers[i] = n;
    i++;
  }

  // Find the number of A2 needed to create the A1.
  // Find the number of tape that would require.
  // If there is enough, stop.
  // Else, go to the next smaller size and see if there is enough paper to create enough of the bigger size.
  // If there is, stop
  // If not, figure out how much is needed and go to the next size.
  // If at the last size, there is not enough, it fails.

  int needed = 1;
  double totalTape = 0;
  for(i = 2; i < smallest; i++)
  {
    totalTape += needed * pow(2, (-3/4.0)-((i-2)/2.0));
    if(numPapers.at(i) >= needed * 2)
    {
      printf("%.12f", totalTape);
      return 0;
    }
    else{
      needed = (needed * 2) - numPapers.at(i);
    }
  }
    totalTape += needed * pow(2, (-3/4.0)-((i-2)/2.0));


  if(numPapers.at(smallest) < needed * 2)
  {
    printf("impossible");
  }
  else
  {
    printf("%.12f", totalTape);
  }

  return 0;
}