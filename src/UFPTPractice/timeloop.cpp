#include <stdio.h>

int main(){
  int n, i = 1;
  scanf("%d", &n);
  while(n != 0){
    printf("%d Abracadabra", i);
    if(n != 1) printf("\n");
    n--;
    i++;
  }
  return 0;
}