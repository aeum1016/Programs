#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  int a, t; scanf("%d %d", &a, &t);
  vector<int> A(a, 0);
  long long sum = 0, evenSum = 0;

  while(a--)
  {
    int n; scanf("%d", &n);
    sum += n;
    if(!(n % 2)) evenSum += n;
    A[A.size()-a-1] = n;
  }

  switch(t)
  {
    case 1:
    {
      printf("7");
      break;
    }
    case 2:
    {
      if(A.at(0) > A.at(1)) printf("Bigger");
      else if(A.at(0) == A.at(1)) printf("Equal");
      else printf("Smaller");
      break;
    }
    case 3:
    {
      int max = fmax(A.at(0), fmax(A.at(1), A.at(2)));
      int min = fmin(A.at(0), fmin(A.at(1), A.at(2)));
      printf("%d", ((A.at(0) != max && A.at(0) != min) ? A.at(0) : (A.at(1) != max && A.at(1) != min) ? A.at(1) : A.at(2)));
      break;
    }
    case 4:
    {
      printf("%lld", sum);
      break;
    }
    case 5:
    {
      printf("%lld", evenSum);
      break;
    }
    case 6:
    {
      string ans = "";		
      for(int i = 0; i < A.size(); i++)		
      {		
        char c = (A.at(i) % 26) + 'a';		
        ans += c;
      }
      cout << ans;
      break;
    }
    case 7:
    {
      vector<bool> seen(A.size(), false);
      int i = 0;
      while(!seen.at(i))
      {
        seen[i] = true;
        i = A.at(i);
        if(i == A.size()-1)
        {
          printf("Done");
          return 0;
        }
        else if (i >= A.size())
        {
          printf("Out");
          return 0;
        }
      }
      printf("Cyclic");
      break;
    }
    default: return 0;
  }
  return 0;
}