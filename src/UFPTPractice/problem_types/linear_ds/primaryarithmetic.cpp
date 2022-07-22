#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

using namespace std;

int main()
{
  int a, b;
  while(scanf("%d %d", &a, &b) != EOF)
  {
    if(a == 0 && b == 0) return 0;

    int max = to_string((int)fmax(a, b)).size();
    int carries = 0;
    bool carry = false;
    for(int i = 0; i < max; i++)
    {
      int expectedDigit = (a/(int)pow(10, i))%10 + (b/(int)pow(10, i))%10 + (carry ? 1 : 0);
      if( expectedDigit >= 10)
      {
        carry = true;
        carries++;
      }
      else carry = false;
    }
    if(carries)
    {
      if(carries == 1) cout << "1 carry operation." << endl;
      else cout << carries << " carry operations." << endl;
    }
    else cout << "No carry operation." << endl;
  }
  return 0;
}