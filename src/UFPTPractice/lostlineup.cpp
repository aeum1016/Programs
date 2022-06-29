#include <stdio.h>

int main(){
  int n; scanf("%d", &n);

  int arr[n];
  arr[0] = 1;

  int i = 1;
  while(i < n)
  {
    int p; scanf("%d", &p);
    arr[p+1] = i+1;
    i++;
  }

  for(int p : arr)
  {
    printf("%d ", p);
  }

  return 0;
}