#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int max(vector<int> A, vector<int> B)
{
  int maxSum = 0;
  bool broken = false;

  int p1 = 1, p2 = 100;
  while(!broken)
  {
    while(A[p1] == 0)
    {
      p1++;
      if(p1 > 100){
        broken = true;
        break;
      }
    }
    while(B[p2] == 0)
    {
      p2--;
      if(p2 <= 0)
      {
        broken = true;
        break;
      }
    }

    if(broken) break;

    maxSum = fmax(maxSum, p1 + p2);
    int min = fmin(A[p1], B[p2]);
    A[p1]-=min;
    B[p2]-=min;
  }

  return maxSum;
}

int main()
{
  int q; scanf("%d\n", &q);
  vector<int> freqA(101, 0);
  vector<int> freqB(101, 0);
  while(q--)
  {
    int aN, bN; scanf("%d %d", &aN, &bN);
    freqA[aN]++;
    freqB[bN]++;
    cout << max(freqA, freqB) << endl;
  }
  return 0;
}