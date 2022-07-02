#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
  int N; scanf("%d", &N);

  while(N--)
  {
      int a = 0, b = 0;
      int x = scanf("%d+%d", &a, &b);
      if(x == 2) printf("%d\n", a+b);
      else 
      {
        scanf("%*s");
        printf("skipped\n");
      }
  }
  return 0;
}