#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int q; scanf("%d\n", &q);

  while(q--)
  {
    double interest, balance, payment;
    cin >> interest >> balance >> payment;

    int months = 0;
    bool impossible = false;
    long long curBalance = round(balance * 100);
    long long interestLL = round(interest * 100);
    long long paymentLL = round(payment * 100);
    while(curBalance > 0)
    {

      long long interest = round(curBalance * interestLL / 10000.0);
      long long newBalance = curBalance + interest - paymentLL;
      
      months++;
      if(newBalance >= curBalance || months > 1200)
      {
        impossible = true;
        break;
      }
      else curBalance = newBalance;
      // break;
    }
    if(impossible) printf("impossible\n");
    else printf("%d\n", months);
  }
}