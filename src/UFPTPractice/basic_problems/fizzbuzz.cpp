#include <stdio.h>

int main()
{
  int x, y, n;
  scanf("%d %d %d", &x, &y, &n);

  int i = 1;
  while(i <= n)
  {
    if(!(i % x) && !(i%y)) printf("FizzBuzz\n");
    else if (!(i%x)) printf("Fizz\n");
    else if (!(i%y)) printf("Buzz\n");
    else printf("%d\n", i);
    i++;
  }
  return 0;
}