#include <stdio.h>
#include <cmath>

void returnABC(int a, int b, int c, char request)
{
  int min = fmin(a, fmin(b, c));
  int max = fmax(a, fmax(b, c));
  int mid = (a == min || a == max) ? ((b == min || b == max) ? c : b) : a; 
  if(request == 'A')
  {
    printf("%d ", min);
  }
  else if (request == 'B')
  {
    printf("%d ", mid);
  }
  else printf("%d ", max);
}

int main()
{
  int a, b, c; scanf("%d %d %d\n", &a, &b, &c);
  for(int i = 0; i < 3; i++)
  {
    char req; scanf("%c", &req);
    returnABC(a, b, c, req);
  }
  return 0;
}